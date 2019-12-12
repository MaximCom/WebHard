/*CLIENT CODE + CLIENT UI CODE */
#include "a.h"
#include "file.h"
#include "maximcom.h"
#include <arpa/inet.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termio.h>
#include <unistd.h>
#define BUFSIZE 2048

int sd;

char fileType(const struct stat *fileInfo);
void error_handling(char *message);
void FILEDOWNLOAD();
void FILEUPLOAD();
void FILESEARCH(char *str);
char *FILESELECT_DOWNLOAD();
char *FILESELECT_UPLOAD();
char *FILESELECT_REMOVE();
void FILE_REMOVE();
int MENUSELECT();
int getch();
void SignUp(int sd);
void SignIn(int sd);
char name[10];
void signalhandler(int signum);
int main(int argc, char **argv) {
    int fd;
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    char str[BUFSIZE];
    int len;
    int num;
    char select1[BUFSIZE] = "DOWNLOAD";
    char select2[BUFSIZE] = "UPLOAD";
    char *select[2][100] = {"FILEDOWNLOAD", "FILEUPLOAD"};
    struct sockaddr_in serv_addr;
    char *ptr;

    signal(SIGINT, signalhandler);

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
    system("clear");
    int count = 0;
    int mycount = 0;
    int mycount1 = 0;
    while (1) {
        count = mainchoice();
        if (count == 1) {
            SignIn(sd);
            break;
        } else if (count == 0) {
            SignUp(sd);
            system("clear");
        }
    }

    while (1) {
        system("clear");
        loginmainPage();
        fflush(stdin);
        num = mypagechoice();
        if (num == 1 || num == 0) {
            strcpy(select1, "SEARCH");
            strcat(select1, " ");
            strcat(select1, "/");
            strcat(select1, name);
            write(sd, select1, strlen(select1));
        }
        if (num == 1) {
            FILESEARCH("FILEDOWNLOAD");
            FILEDOWNLOAD();
        } else if (num == 2) {
            FILESEARCH("FILEUPLOAD");
            FILEUPLOAD();
        } else if (num == 0) {
            FILESEARCH("FILEREMOVE");
            FILE_REMOVE();
        }
        fflush(stdout);
        fflush(stdin);
        system("clear");
    }
    close(sd);
    return 0;
}

void SignUp(int sd) {
    char buf[BUFSIZE];
    int size;
    char lid[BUFSIZE];
    char lpassword[BUFSIZE];
    char cpassword[BUFSIZE];
    char signup[BUFSIZE] = "SIGNUP";
    int n=getch();
    while (1) {
        system("clear");
        joinMemberPage();

        move_cur(44, 22);
        printf("ID 입력");

        move_cur(44, 29);
        printf("PASSWORD 입력");

        move_cur(44, 36);
        printf("PASSWORD 재입력");

        move_cur(52, 22);
        scanf("%s", lid);

        move_cur(58, 29);
        scanf("%s", lpassword);

        move_cur(60, 36);
        scanf("%s", cpassword);

        if (strcmp(lpassword, cpassword) != 0) {
            while (1) {
                move_cur(42, 39);
                printf("\x1b[31m비밀번호가 일치하지 않습니다.\x1b[0m");
                move_cur(60, 36);
                printf("                    ");
                move_cur(60, 36);
                scanf("%s", cpassword);
                printf("%s", cpassword);
                if (strcmp(lpassword, cpassword) == 0)
                    break;
            }
        } else {
            memset(signup, 0, BUFSIZE);
            strcpy(signup, "SIGNUP");
            strcat(signup, " ");
            strcat(signup, lid);
            strcat(signup, " ");
            strcat(signup, lpassword);
            write(sd, signup, strlen(signup));
            read(sd, buf, BUFSIZE);
            if (strcmp(buf, "OVERLAP ID") == 0) {
                move_cur(42, 39);
                printf("\x1b중복된 아이디 입니다.(다시 입력 받을려면 "
                       "엔터)\x1b[0m");
                getchar(); //엔터 받을 때까지 대기
            } else if (strcmp(buf, "SUCCESS SIGNUP") == 0) {
                fflush(stdin);

                return;
            }
        }
    }
}
void SignIn(int sd) {
    char *message;
    char buf[BUFSIZE];
    char log[BUFSIZE] = "LOGIN";
    char password[BUFSIZE];
    while (1) {
        system("clear");
        loginPage();
        move_cur(44, 22);
        printf("ID 입력");
        move_cur(44, 28);
        printf("PASSWORD 입력");
        move_cur(52, 22);
        scanf("%s", name); //전역 변수 나중에 파일 다운이나 업로드에도 계속
                           //사용할려고 전역 사용
        move_cur(58, 28);
        scanf("%s", password);
        // system("clear");

        memset(log, 0, BUFSIZE);
        strcpy(log, "LOGIN");
        strcat(log, " ");
        strcat(log, name);
        strcat(log, " ");
        strcat(log, password);
        memset(buf, 0, BUFSIZE);
        write(sd, log, strlen(log));

        read(sd, buf, BUFSIZE);
        if (strcmp(buf, "FAILED LOGIN") == 0) {
            move_cur(42, 39);
            printf("로그인 실패 다시 입력.(엔터시 재입력)");
            int n = getch();
            getchar(); //엔터 받을 때까지 대기
            system("clear");
        } else if (strcmp(buf, "SUCCESS LOGIN") == 0) {
            break;
        }
    }
}
void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
void FILEDOWNLOAD() {
    char buf[BUFSIZE] = {
        0,
    };
    char cbuf[BUFSIZE] = {
        0,
    };
    char *file;
    char tok[BUFSIZE];
    char filename[BUFSIZE];
    char *tokstr;
    char *file2;
    int len;
    int num;
    int fd;
    int filesize;
    char f[BUFSIZE] = "DOWNLOAD_FILE";

    file2 = FILESELECT_DOWNLOAD();
    if (strcmp(file2, "exit") == 0) {
        return;
    }
    /* 원하는 데이터를 입력 */
    strcpy(tok, file2);

    strcat(f, " ");
    strcat(f, "/");
    strcat(f, tok);
    write(sd, f, strlen(f));

    // /DOWNLOAD_FILE /path/filename
    /*filesize read*/
    read(sd, &filesize, sizeof(int));
    /*filename tok */
    strcat(tok, "/");
    tokstr = strtok(tok, "/");
    while (tokstr != NULL) {
        strcpy(filename, tokstr);
        tokstr = strtok(NULL, "/");
    }

    /* 수신 한 데이터를 저장 할 파일 오픈 */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        error_handling("File open error3");

    if (filesize != 0) {
        file = (char *)malloc(filesize + 1);

        int sum = 0;
        while (1) {
            memset(file, 0x00, filesize);
            len = read(sd, file, filesize);

            write(fd, file, len);

            sum += len;

            fflush(stdout);
            fflush(stdin);

            if (sum == filesize) {
                break;
            }
        }

        free(file);
    }

    /* 전송해 준것에 대한 감사의 메시지 전달 */
    write(sd, "Thank you", BUFSIZE);
    close(fd);
}
void FILEUPLOAD() {
    char buf[BUFSIZE];
    char *file;
    char *file2;
    struct stat fileinfo;
    char cbuf[BUFSIZE];
    int len, read_len;
    int num;
    int fd;
    char f[BUFSIZE] = "UPLOAD";
    char cwd[BUFSIZE];
    int filesize;
    memset(cwd, 0, BUFSIZE);
    if (getcwd(cwd, BUFSIZE) == NULL) {
        perror("getcwd() error!");
        exit(-1);
    }
    // file2 = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
    // read(sd, cbuf, sizeof(cbuf)); //서버에서 업로드 조건문 통과 답을받음
    file2 = FILESELECT_UPLOAD();
    if (strcmp(file2, "exit") == 0) {
        return;
    }
    /* 원하는 데이터를 입력 */
    strcpy(cbuf, file2);
    strcat(cwd, "/");
    strcat(cwd, cbuf);

    stat(cwd, &fileinfo);
    system("clear");
    filesize = fileinfo.st_size;
    file = (char *)malloc(filesize);
    fd = open(cwd, O_RDONLY, 0644);

    if (fd == -1) {
        error_handling("FILE open error");
    }
    strcat(f, " ");
    strcat(f, name);
    strcat(f, " ");
    strcat(f, cbuf);
    strcat(f, " ");
    sprintf(buf, "%d", filesize);
    strcat(f, buf);

    // UPLOAD_FILE/ID/FILENAME Filesize
    write(sd, f, strlen(f)); //서버에 파일명 전송

    // memset(buf, 0, BUFSIZE);
    read(sd, buf, BUFSIZE);

    if (strcmp(buf, "Overlap File") == 0) {
    goto1:
        printf("덮어 쓰겠습니까??? y/n \n");
        memset(buf, 0, BUFSIZE);
        scanf("%s", buf);
        write(sd, buf, strlen(buf));
        if (strcmp(buf, "n") == 0 || strcmp(buf, "N") == 0) {
            int n = getch();
            return;
        } else {
            memset(buf, 0, BUFSIZE);
            read(sd, buf, BUFSIZE);
            if (strcmp(buf, "Overlap File") == 0) {
                printf("Invalid Input\n");
                goto goto1;
            } else if (strcmp(buf, "Valid Input") == 0) {
                read_len = 0;

                memset(file, 0x00, filesize);
                read_len = read(fd, file, filesize);
                send(sd, file, read_len, 0);
                fflush(stdout);
                fflush(stdin);

                len = read(sd, cbuf, BUFSIZE);
                // write(1, cbuf, len);
                fflush(stdout);
                fflush(stdin);
                getchar();
            }
        }
    } else if (strcmp(buf, "OK") == 0) {
        // read(fd, file, filesize);
        // file[filesize] = '\0';

        // write(sd, file, strlen(file));
        read_len = 0;

        memset(file, 0x00, filesize);
        read_len = read(fd, file, filesize);
        send(sd, file, read_len, 0);
        fflush(stdout);
        fflush(stdin);

        len = read(sd, cbuf, BUFSIZE);
        // write(1, cbuf, len);
        fflush(stdout);
        fflush(stdin);
    }

    free(file);

    close(fd);
}
void FILESEARCH(char *str) {
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
    fflush(stdout);
    if (strcmp(str, "FILEDOWNLOAD") == 0 || strcmp(str, "FILEREMOVE") == 0) {
        fd = open("FileSearch", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        // printf("filedownload search\n");
        read(sd, &NameLen, sizeof(int));
        str2 = (char *)malloc(NameLen + 1);
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
char *FILESELECT_DOWNLOAD() {
    char **str;
    char strc[BUFSIZE] = {'\0'};
    char *dir;
    char *curpath;
    char *ptr;
    char ptr2[BUFSIZE];
    char *file;
    int idx = 0;
    int len, fd, n, b = 0;
    int index = 0;
    int i = 0;
    int rsize = 0;
    int num = 0;
    struct stat fileinfo;

    curpath = (char *)malloc(BUFSIZE);
    strcpy(curpath, name); //최초의 경로
reselect:
    fd = open("FileSearch", O_RDONLY, 0644);
    if (fd == -1) {
        perror("FILESELECT FILE open fail");
        exit(1);
    }
    index = 0;
    memset(strc, 0, BUFSIZE);
    rsize = read(fd, strc, sizeof(char));
    while (rsize > 0) {
        if (strcmp(strc, "\n") == 0)
            index++;
        rsize = read(fd, strc, sizeof(char));
    }
    close(fd);
    str = (char **)malloc(sizeof(char *) * index);
    fd = open("FileSearch", O_RDONLY);
    if (fd == -1)
        perror("FILESELECT FILE open fail2");
    memset(&fileinfo, 0, sizeof(struct stat));
    stat("FileSearch", &fileinfo);
    read(fd, strc, fileinfo.st_size);
    ptr = strtok(strc, "\n");
    i = 0;
    while (ptr != NULL) {
        str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
        strcpy(str[i], ptr);
        ptr = strtok(NULL, "\n");
        i++;
    }
    close(fd);
    system("clear");
    str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
    strcpy(str[i], "exit");
    index++;
    b = 0;
    num = 0;
    idx = 0;

    draw(index - 1);

    move_cur(33, 15);
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int j = 16; j < 38; j++) {
        move_cur(33, j);
        printf("┃");
        if (idx < index - 1) {
            printf(b == idx ? ">> %s" : "   %s", str[idx]);
            len = strlen(str[idx]) + 3;
        } else if (j == 37) {
            printf("   %s", str[index - 1]);
            len = strlen(str[index - 1]) + 3;
        } else {
            len = 0;
        }
        for (int k = 0; k < 66 - len; k++) {
            printf(" ");
        }
        printf("┃");
        idx++;
    }
    move_cur(33, 38);
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    printf("\n");

    while (1) {
        n = getch();
        if (n == 10) {
            break;
        }
        if (n == 65 || n == 66) {
            system("clear");
            idx = 0;
            if (n == 65) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num > 0)
                    num--;

                b = num % index;
                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            } else if (n == 66) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num < index - 1)
                    num++;

                b = num % index;

                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            }
        }
    }
    if (strcmp(str[num], "exit") == 0) {

        strcpy(curpath, str[num]);
        return curpath;
    }
    file = (char *)malloc(strlen(str[num]) + 1);
    // system("clear");
    dir = (char *)malloc(BUFSIZE);
    // sleep(1000);
    strcpy(file, str[num]);
    strcpy(dir, "IS_DIRECTORY");
    strcat(dir, " ");
    strcat(dir, "/");

    if (strcmp(file, "..")) {
        if (strcmp(curpath, "/")) {
            strcat(dir, curpath);
            strcat(dir, "/");
        }
        strcat(dir, file);
    }

    write(sd, dir, strlen(dir));
    memset(ptr2, 0, BUFSIZE);
    read(sd, ptr2, BUFSIZE);

    if (strcmp(ptr2, "DIRECTORY") == 0) {
        strcpy(curpath, (!strcmp(file, "..") ? "/" : file));

        memset(dir, 0, BUFSIZE);
        strcpy(dir, "SEARCH");
        strcat(dir, " ");
        if (strcmp(file, ".."))
            strcat(dir, "/");

        strcat(dir, curpath);
        //  strcat(dir, file);

        write(sd, dir, strlen(dir));

        FILESEARCH("FILEDOWNLOAD");

        //for (i = 0; i < index; i++)
        //    free(str[i]);
        //free(str);

        system("clear");
        goto reselect; //위로 다시 진행
    } else if (strcmp(ptr2, "FILE") == 0) {
        // curpath/filename return
        strcat(curpath, "/");
        strcat(curpath, file);
        // strcat(file, curpath);

        //for (i = 0; i < index; i++)
        //    free(str[i]);
        //free(str);
        return curpath;
    }
}
char *FILESELECT_UPLOAD() {
    char **str;
    char strc[100] = {'\0'};
    char *ptr;
    char *ptr2;
    char file[BUFSIZE];
    int fd;
    int index = 0;
    int i = 0;
    int rsize = 0;
    int num = 0;
    int b = 0, idx = 0, n = 0, len = 0;
    struct stat fileinfo;

    fd = open("FileSearch", O_RDONLY, 0644);
    if (fd == -1) {
        perror("FILESELECT FILE open fail");
        exit(1);
    }
    rsize = read(fd, strc, sizeof(char));
    while (rsize > 0) {
        if (strcmp(strc, "\n") == 0)
            index++;
        rsize = read(fd, strc, sizeof(char));
    }
    close(fd);

    str = (char **)malloc(sizeof(char *) * index);
    fd = open("FileSearch", O_RDONLY);
    if (fd == -1)
        perror("FILESELECT FILE open fail2");

    stat("FileSearch", &fileinfo);
    read(fd, strc, fileinfo.st_size);
    i = 0;
    ptr = strtok(strc, "\n");
    while (ptr != NULL) {
        str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
        strcpy(str[i], ptr);
        ptr = strtok(NULL, "\n");
        i++;
    }
    str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
    strcpy(str[i], "exit");
    close(fd);
    index++;
    system("clear");
    b = 0;
    num = 0;
    draw(index - 1);
    move_cur(33, 15);

    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int j = 16; j < 38; j++) {
        move_cur(33, j);
        printf("┃");
        if (idx < index - 1) {
            printf(b == idx ? ">> %s" : "   %s", str[idx]);
            len = strlen(str[idx]) + 3;
        } else if (j == 37) {
            printf("   %s", str[index - 1]);
            len = strlen(str[index - 1]) + 3;
        } else {
            len = 0;
        }
        for (int k = 0; k < 66 - len; k++) {
            printf(" ");
        }
        printf("┃");
        idx++;
    }
    move_cur(33, 38);
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    printf("\n");

    while (1) {
        n = getch();
        if (n == 10) {
            break;
        }
        if (n == 65 || n == 66) {
            system("clear");
            idx = 0;
            if (n == 65) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num > 0)
                    num--;

                b = num % index;
                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            } else if (n == 66) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num < index - 1)
                    num++;

                b = num % index;

                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            }
        }
    }
    char *curpath;
    curpath = (char *)malloc(BUFSIZE);
    if (strcmp(str[num], "exit") == 0) {

        strcpy(curpath, str[num]);
        return curpath;
    }

    strcpy(file, str[num]); //포인터끼리
    strcpy(curpath, file); //배열을 포인터에?? 뭘까여 이렇게하면도;네여

    for (i = 0; i < index; i++)
        free(str[i]);
    free(str);

    return curpath;
}
void FILE_REMOVE() {
    char buf[BUFSIZE] = {
        0,
    };
    char cbuf[BUFSIZE] = {
        0,
    };
    char *file;
    char tok[BUFSIZE];
    char filename[BUFSIZE];
    char *tokstr;
    char *file2;
    int len;
    int num;
    int fd;
    int filesize;
    char f[BUFSIZE] = "REMOVE_FILE";

    file2 = FILESELECT_REMOVE();
    if (strcmp(file2, "exit") == 0) {
        return;
    }
    /* 원하는 데이터를 입력 */
    strcpy(tok, file2);

    strcat(f, " ");
    strcat(f, "/");
    strcat(f, name);
    strcat(f, "/");
    strcat(f, tok);
    write(sd, f, strlen(f));

    // REMOVE_FILE /path/filename
    /*filesize read*/
    read(sd, buf, BUFSIZE);
    free(file);
}

char *FILESELECT_REMOVE() {
    char **str;
    char strc[100] = {'\0'};
    char *ptr;
    char *ptr2;
    char file[BUFSIZE];
    int fd;
    int index = 0;
    int i = 0;
    int rsize = 0;
    int num = 0;
    int b = 0, idx = 0, n = 0, len = 0;
    struct stat fileinfo;

    fd = open("FileSearch", O_RDONLY, 0644);
    if (fd == -1) {
        perror("FILESELECT FILE open fail");
        exit(1);
    }
    rsize = read(fd, strc, sizeof(char));
    while (rsize > 0) {
        if (strcmp(strc, "\n") == 0)
            index++;
        rsize = read(fd, strc, sizeof(char));
    }
    close(fd);

    str = (char **)malloc(sizeof(char *) * index);
    fd = open("FileSearch", O_RDONLY);
    if (fd == -1)
        perror("FILESELECT FILE open fail2");

    stat("FileSearch", &fileinfo);
    read(fd, strc, fileinfo.st_size);

    ptr = strtok(strc, "\n");
    while (ptr != NULL) {
        str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
        if (strcmp(ptr, "..") == 0) {
            ptr = strtok(NULL, "\n");
            index--;
            continue;
        }
        strcpy(str[i], ptr);
        ptr = strtok(NULL, "\n");
        i++;
    }
    close(fd);
    str[i] = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
    strcpy(str[i], "exit");
    index++;
    system("clear");
    b = 0;
    num = 0;
    draw(index - 1);
    move_cur(33, 15);
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int j = 16; j < 38; j++) {
        move_cur(33, j);
        printf("┃");
        if (idx < index - 1) {
            printf(b == idx ? ">> %s" : "   %s", str[idx]);
            len = strlen(str[idx]) + 3;
        } else if (j == 37) {
            printf("   %s", str[index - 1]);
            len = strlen(str[index - 1]) + 3;
        } else {
            len = 0;
        }
        for (int k = 0; k < 66 - len; k++) {
            printf(" ");
        }
        printf("┃");
        idx++;
    }
    move_cur(33, 38);
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    printf("\n");

    while (1) {
        n = getch();
        if (n == 10) {
            break;
        }
        if (n == 65 || n == 66) {
            system("clear");
            idx = 0;
            if (n == 65) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num > 0)
                    num--;

                b = num % index;
                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            } else if (n == 66) {
                draw(index);
                move_cur(33, 15);
                printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┓");
                if (num < index - 1)
                    num++;

                b = num % index;

                for (int j = 16; j < 38; j++) {
                    move_cur(33, j);
                    printf("┃");
                    if (idx < index - 1) {
                        printf(b == idx ? ">> %s" : "   %s", str[idx]);
                        len = strlen(str[idx]) + 3;
                    } else if (j == 37) {
                        printf(b == index - 1 ? ">> %s" : "   %s",
                               str[index - 1]);
                        len = strlen(str[index - 1]) + 3;
                    } else {
                        len = 0;
                    }
                    for (int k = 0; k < 66 - len; k++) {
                        printf(" ");
                    }
                    printf("┃");
                    idx++;
                }
                move_cur(33, 38);
                printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                       "━━━━━━━━━━━━━━━━━━━━━━━━┛");
            }
        }
    }
    char *curpath;
    curpath = (char *)malloc(BUFSIZE);
    if (strcmp(str[num], "exit") == 0) {

        strcpy(curpath, str[num]);
        return curpath;
    }
    strcpy(file, str[num]); //포인터끼리
    strcpy(curpath, file); //배열을 포인터에?? 뭘까여 이렇게하면도;네여

    for (i = 0; i < index; i++)
        free(str[i]);
    free(str);
    return curpath;
}
void signalhandler(int signum) {
    if (SIGINT == signum) {
        write(sd, "EOI", 3);
        shutdown(sd, SHUT_WR);
        fflush(stdin);
        fflush(stdout);
        exit(1);
    }
}
