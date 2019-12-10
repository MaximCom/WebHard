#include "server.h"
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SPLIT_COUNT 20

void cleanupHandler(void *arg) {
    pthread_mutex_lock(&mutex);
    loginUser--;
    pthread_mutex_unlock(&mutex);
    pthread_cancel(pthread_self());
}

int mySplit(char (*result)[MAX_BUF], char *buf, char *ch) {
    int len = strlen(buf);
    char *token;
    int index = 0;

    if (buf[len - 1] == '\n')
        buf[--len] = 0;
    if (buf[len - 1] == '\r')
        buf[--len] = 0;

    token = strtok(buf, ch);
    while (token) {
        strcpy(result[index++], token);
        token = strtok(NULL, ch);
    }
    return index;
}

void *thread_main(void *argv) {
    int sock = *((int *)argv);
    char buf[MAX_BUF];
    char *file_buf;
    char split_buf[SPLIT_COUNT][MAX_BUF];
    int split_count;

    char path[MAX_PATH] = {
        0,
    };
    struct stat fileInfo;
    struct dirent *dirInfo;
    DIR *dir;
    int length;

    int file_descriptor;
    FILE *std_file_descriptor;
    char user_info[2][MAX_BUF];
    int flag; // userId, password check

    pthread_cleanup_push(cleanupHandler, NULL);

    while (1) {
        memset(buf, 0, MAX_BUF);
        read(sock, buf, MAX_BUF - 1);
	printf("%s\n", buf);
        split_count = mySplit(split_buf, buf, " ");

        if (!strcmp(split_buf[0], "SEARCH")) {
            // SEARCH /path
            if (split_count != 2)
                continue;

            memset(path, 0, MAX_PATH);
            strcpy(path, upload_rootPath);
            strcat(path, split_buf[1]);

            if (stat(path, &fileInfo) == -1)
                errorHandler("Stat");

            if (!S_ISDIR(fileInfo.st_mode)) {
                write(sock, "Invalid FilePath", 17);
                continue;
            }
            dir = opendir(path);
            memset(buf, 0, MAX_BUF);
            while ((dirInfo = readdir(dir)) != NULL) {
		if (!strcmp(path, upload_rootPath2))
		    if(!strcmp(dirInfo->d_name, ".."))
			continue;
                if (!strcmp(dirInfo->d_name, "."))
                    continue;
                strcat(buf, dirInfo->d_name);
                strcat(buf, "\n");
            }

            length = strlen(buf);
            write(sock, &length, sizeof(length));
            write(sock, buf, strlen(buf));

            closedir(dir);
        } else if (!strcmp(split_buf[0], "IS_DIRECTORY")) {
            // IS_DIRECTORY /file
            if (split_count != 2)
                continue;
	    
            memset(path, 0, MAX_PATH);
            strcpy(path, upload_rootPath);
            strcat(path, split_buf[1]);

            if (stat(path, &fileInfo) == -1)
                errorHandler("Stat");

            if (!S_ISDIR(fileInfo.st_mode))
                write(sock, "FILE", 5);
            else
                write(sock, "DIRECTORY", 10);
        } else if (!strcmp(split_buf[0], "DOWNLOAD_FILE")) {
            // DOWNLOAD_FILE /yjh/test.txt
            if (split_count != 2)
                continue;

            memset(path, 0, MAX_PATH);
            strcpy(path, upload_rootPath);
            strcat(path, split_buf[1]);

            if (stat(path, &fileInfo) == -1)
                errorHandler("Stat");

            if (!S_ISREG(fileInfo.st_mode)) {
                continue;
            }

            length = fileInfo.st_size;
            write(sock, &length, sizeof(length));
            if (length != 0) {
                file_descriptor = open(path, O_RDONLY);
                file_buf = (char *)malloc(sizeof(char) * length + 1);

                memset(file_buf, 0, length + 1);
                if ((read(file_descriptor, file_buf, length)) == -1)
                    errorHandler("Read");
                
                write(sock, file_buf, length);
 		fflush(stdout);
                fflush(stdin);
                free(file_buf);

		close(file_descriptor);
            }

            memset(buf, 0, MAX_BUF);
            read(sock, buf, MAX_BUF);
            if (strcmp(buf, "Thank you"))
                errorHandler("File Upload");
        } else if (!strcmp(split_buf[0], "UPLOAD")) {
            // UPLOAD yjh filename filesize
            // Overlap File
            if (split_count != 4)
                continue;

            memset(path, 0, MAX_PATH);
            strcpy(path, upload_rootPath);
            strcat(path, "/");
            strcat(path, split_buf[1]);
            strcat(path, "/");

            if (stat(path, &fileInfo) == -1)
                mkdir(path, 0755);

            strcat(path, split_buf[2]);
            if (stat(path, &fileInfo) != -1) {
            goto1:
                write(sock, "Overlap File", 13);

                memset(buf, 0, MAX_BUF);
                read(sock, buf, MAX_BUF);

                if (!strcmp(buf, "n") || !strcmp(buf, "N"))
                    continue;
                else if (!strcmp(buf, "EOI")) {
                    close(sock);
                    break;
                } else if (strcmp(buf, "y") && strcmp(buf, "Y"))
                    goto goto1;
                else {
                    write(sock, "Valid Input", 12);
                }
            } else {
                write(sock, "OK", 3);
            }

            file_descriptor = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
            length = atoi(split_buf[3]);
            file_buf = (char *)malloc(length);
            int file_read_len;

            // read(sock, file_buf, length);
            // write(file_descriptor, file_buf, length);

            int sum = 0;
            while (1) {
                memset(file_buf, 0x00, length);
                file_read_len = read(sock, file_buf, length);

                write(file_descriptor, file_buf, file_read_len);

                sum += file_read_len;

                fflush(stdout);
                fflush(stdin);

                if (sum == length) 
                    break;
            }

            if (stat(path, &fileInfo) == -1)
                errorHandler("Stat");

            if (fileInfo.st_size == length)
                write(sock, "Upload Success!", 16);
            else 
                write(sock, "Upload Failed!", 15);

            close(file_descriptor);
            free(file_buf);
        } else if (!strcmp(split_buf[0], "SIGNUP")) {
            // SIGNUP id password
	    if (split_count != 3)
		    continue;
            std_file_descriptor = fopen(userFile, "a+");
            if (std_file_descriptor < 0)
                errorHandler("userFile Open");
	    
	    memset(path, 0, MAX_PATH);
	    strcpy(path, upload_rootPath2);
	    strcat(path, split_buf[1]);

	    mkdir(path, 0755);

            flag = 0;
            memset(buf, 0, MAX_BUF);
            while (fgets(buf, MAX_BUF, std_file_descriptor)) {
                if (mySplit(user_info, buf, " ") != 2)
                    break;
                if (!strcmp(user_info[0], split_buf[1])) {
                    write(sock, "OVERLAP ID", 11);
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                write(sock, "SUCCESS SIGNUP", 15);

                memset(buf, 0, MAX_BUF);
                strcat(buf, split_buf[1]);
                strcat(buf, " ");
                strcat(buf, split_buf[2]);
                strcat(buf, "\n");
                fputs(buf, std_file_descriptor);
            }
            fclose(std_file_descriptor);
        } else if (!strcmp(split_buf[0], "LOGIN")) {
            // LOGIN id password
	    if (split_count != 3)
		    continue;
            std_file_descriptor = fopen(userFile, "r");

            flag = 0;
            memset(buf, 0, MAX_BUF);
            while (fgets(buf, MAX_BUF, std_file_descriptor)) {
                if (mySplit(user_info, buf, " ") != 2)
                    break;
                if (!strcmp(user_info[0], split_buf[1])) {
                    if (!strcmp(user_info[1], split_buf[2])) {
                        write(sock, "SUCCESS LOGIN", 14);
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag)
                write(sock, "FAILED LOGIN", 13);

            fclose(std_file_descriptor);
        }else if (!strcmp(split_buf[0], "REMOVE_FILE")) {
	    // REMOVE_FILE /path/file
	    if (split_count != 2)
		    continue;
	    memset(path, 0, MAX_PATH);	
	    strcpy(path, upload_rootPath);
	    strcat(path, split_buf[1]);

	    if (stat(path, &fileInfo) == -1)
		    errorHandler("Stat");
            if (S_ISDIR(fileInfo.st_mode))
                    continue;
	    
	    if(remove(path) == 0)
		    write(sock, "SUCCESS REMOVE!", 16);
	    else
		    write(sock, "FAILED REMOVE!", 15);
	}else if (!strcmp(split_buf[0], "EOI")) {
            close(sock);
            break;
        }
    }

    pthread_cleanup_pop(1);
}
