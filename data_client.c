#include <arpa/inet.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termio.h>
#include <unistd.h>
#define BUFSIZE 100
char fileType(const struct stat *fileInfo);
void error_handling(char *message);
void FILEDOWNLOAD(int sd);
void FILEUPLOAD(int sd);
void FILESEARCH(int sd, char *str);
void FILESELECT(char *file);
int MENUSELECT();
int getch();

int main(int argc, char **argv) {
    int fd;
    int sd;
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    char str[BUFSIZE];
    int len;
    int num;
    struct sockaddr_in serv_addr;

    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    /* 서버 접속을 위한 소켓 생성 */
    sd = socket(PF_INET, SOCK_STREAM, 0);
    if (sd == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!");
    while (1) {
        fflush(stdin);
        system("clear");
        num = MENUSELECT();
        num = num + 1;
        write(sd, &num, sizeof(int));

        if (num == 1) {
            FILESEARCH(sd, "FILEDOWNLOAD");

            FILEDOWNLOAD(sd);

        } else if (num == 2) {
            FILESEARCH(sd, "FILEUPLOAD");
            FILEUPLOAD(sd);
        }
        fflush(stdout);
        fflush(stdin);
    }
    close(sd);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
void FILEDOWNLOAD(int sd) {
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    char *file;
    char *file2;
    int len;
    int num;
    int fd;
    int filesize;

    read(sd, cbuf, sizeof(cbuf));
    printf("%s\n", cbuf);
    fflush(stdout);

    FILESELECT(file2);
    /* 원하는 데이터를 입력 */
    printf("\n>> %s", cbuf);
    strcpy(cbuf, file2);
    printf("\n>> %s", cbuf);
    write(sd, cbuf, strlen(cbuf) + 1);
    /*filesize read*/
    read(sd, &filesize, sizeof(int));
    file = (char *)malloc(filesize);
    /* 수신 한 데이터를 저장 할 파일 오픈 */
    fd = open(cbuf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        error_handling("File open error3");

    /* 데이터를 전송 받아서 파일에 저장한다 */
    len = read(sd, file, filesize);
    write(fd, file, len);

    /* 전송해 준것에 대한 감사의 메시지 전달 */
    write(sd, "Thank you\n", 10);
    free(file);
    free(file2);
    close(fd);
}
void FILEUPLOAD(int sd) {
    char buf[BUFSIZE];
    char *file;
    char *file2;
    struct stat fileinfo;
    char cbuf[BUFSIZE];
    int len;
    int num;
    int fd;
    char cwd[100] = {'\0'};
    int filesize;
    if (getcwd(cwd, 100) == NULL) {
        perror("getcwd() error!");
        exit(-1);
    }
    file2 = (char *)malloc(sizeof(char) * 100);
    read(sd, cbuf, sizeof(cbuf)); //서버에서 업로드 조건문 통과 답을받음
    FILESELECT(file2);
    /* 원하는 데이터를 입력 */
    strcpy(cbuf, file2);

    strcat(cwd, "/");
    strcat(cwd, cbuf);
    stat(cwd, &fileinfo);
    printf("UPLOAD FILE PATH INPUT : %s\n", cwd);
    filesize = fileinfo.st_size;
    file = (char *)malloc(filesize);
    fd = open(cwd, O_RDONLY);

    if (fd == -1) {
        error_handling("FILE open error");
    }
    write(sd, cbuf, BUFSIZE);          //서버에 파일명 전송
    write(sd, &filesize, sizeof(int)); // filesize 부터 전송
    /* 서버에 데이터 전송 */
    while ((len = read(fd, file, filesize)) != 0) {
        write(sd, file, len);
    }

    len = read(sd, cbuf, BUFSIZE);
    write(1, cbuf, len);
    free(file);
    free(file2);
    close(fd);
}
void FILESEARCH(int sd, char *str) {
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    int fd;
    int len;
    int fd2;
    int NameLen = 0;
    char *str2;
    if (fd == -1) {
        error_handling("FILE open error");
    }
    if (strcmp(str, "FILEDOWNLOAD") == 0) {
        fd = open("FileSearch", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        printf("filedownload search\n");
        read(sd, &NameLen, sizeof(int));
        str2 = (char *)malloc(NameLen);
        read(sd, str2, NameLen);
        write(fd, str2, NameLen);

        close(fd);

    } else if (strcmp(str, "FILEUPLOAD") == 0) {
        struct stat fileinfo;
        DIR *dirp;
        struct dirent *dirinfo;
        fd = open("FileSearch", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (stat("./", &fileinfo) == -1) {
            error_handling("stat() error");
        }
        if (!S_ISDIR(fileinfo.st_mode)) {
            fprintf(stderr, " not directory\n");
        }
        dirp = opendir("./");
        char *ptr;
        while ((dirinfo = readdir(dirp)) != NULL) {
            if (stat(dirinfo->d_name, &fileinfo) == -1) {
                perror("stat() error!");
            }
            if (fileType(&fileinfo) == '-') {
                ptr = strcat(dirinfo->d_name, "\n");
                write(fd, dirinfo->d_name, strlen(dirinfo->d_name));
            }
        }
        close(fd);

        closedir(dirp);
    }
}
void FILESELECT(char *file) {
    char **str;
    char strc[100] = {'\0'};
    char *ptr;
    char *ptr2;
    int fd;
    int index = 0;
    int i = 0;
    int rsize = 0;
    int num = 0;
    int n;
    int b;
    struct stat fileinfo;
    printf("Ds");
    fd = open("FileSearch", O_RDONLY, 0644);
    if (fd == -1) {
        perror("FILESELECT FILE open fail");
        exit(1);
    }
    rsize = read(fd, strc, sizeof(char));
    while (rsize > 0) {

        if (strcmp(strc, "\n") == 0) {
            index++;
        }
        rsize = read(fd, strc, sizeof(char));
    }
    close(fd);
    printf("index %d\n", index);
    str = (char **)malloc(sizeof(char *) * index);
    fd = open("FileSearch", O_RDONLY);
    if (fd == -1) {
        perror("FILESELECT FILE open fail2");
    }
    stat("FileSearch", &fileinfo);
    read(fd, strc, fileinfo.st_size);
    ptr = strtok(strc, "\n");
    while (ptr != NULL) {
        str[i] = (char *)malloc(strlen(ptr));
        strcpy(str[i], ptr);
        ptr = strtok(NULL, "\n");
        i++;
    }
    close(fd);
    system("clear");
    printf(">>");
    for (int i = 0; i < index; i++) {
        printf("%s\n", str[i]);
    }

    while (1) {

        n = getch();

        if (n == '\n') {
            break;
        }
        system("clear");
        if (n == 65) {

            if (num != 0) {
                num--;
            }
            b = num % index;
            for (i = 0; i < index; i++) {
                if (b == i) {
                    printf(">>");
                }
                printf("%s\n", str[i]);
            }
        }
        if (n == 66) {

            if (num != index - 1) {
                num++;
            }
            b = num % index;
            for (i = 0; i < index; i++) {
                if (b == i) {
                    printf(">>");
                }
                printf("%s\n", str[i]);
            }
        }
    }
    file = (char *)malloc(strlen(str[num]));
    strcpy(file, str[num]);
    file[strlen(file)] = '\0';
    for (int i = 0; i < index; i++) {
        free(str[i]);
    }
    free(str);
    printf(">> str %s\n", file);
}
int MENUSELECT() {
    int num = 0;
    char n;
    int index = 2;
    int i = 0;
    int b = 0;
    printf("%c[1;33m", 27);
    printf("1. FILEDOWNLOAD ");
    printf("%c[0m", 27);
    printf("2. FILEUPLOAD ");
    while (1) {

        n = getch();
        if (n == '\n') {
            break;
        }
        system("clear");
        if (n == 68) {
            num = 0;

            printf("%c[1;33m", 27);
            printf("1. FILEDOWNLOAD ");
            printf("%c[0m", 27);
            printf("2. FILEUPLOAD ");
            printf("\n");
        }
        if (n == 67) {
            num = 1;

            printf("%c[0m", 27);
            printf("1. FILEDOWNLOAD ");
            printf("%c[1;33m", 27);

            printf("2. FILEUPLOAD ");
            printf("\n");
        }
    }
    printf("%c[0m", 27);
    system("clear");
    return num;
}
int getch() {
    int ch;
    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
