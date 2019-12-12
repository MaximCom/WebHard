#include "server.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CLNT 10

char *upload_rootPath = "/home/ch4njun/Project/SERVER/upload_path";
char *upload_rootPath2 = "/home/ch4njun/Project/SERVER/upload_path/";
char *userFile = "./userFile.txt";
char *logFile = "./log/log.txt";

int loginUser = 0;
pthread_mutex_t mutex;

void errorHandler(char *message) {
    printf("%s Error!\n", message);
    exit(-1);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in servAddr, clntAddr;
    int servSock, clntSock;
    int addrSize;
    int i;

    pthread_t clntThread[MAX_CLNT];
    pthread_t serverThread;

    pthread_mutex_init(&mutex, NULL);
    if ((servSock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        errorHandler("Socket");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]));

    if (bind(servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        errorHandler("Bind");

    //if (pthread_create(&serverThread, NULL, thread_program, (void *)&clntSock) != 0)
    //    errorHandler("Pthread_create2");

    while (1) {
        listen(servSock, MAX_CLNT);
        // printf("[*] Wait...\n");

        addrSize = sizeof(clntAddr);
        clntSock = accept(servSock, (struct sockaddr *)&clntAddr, &addrSize);
        if (clntSock < 0)
            errorHandler("Accept");

        if (loginUser == MAX_CLNT) {
            printf("[*] The server is busy\n");
            shutdown(clntSock, SHUT_RDWR);
            continue;
        }

        if (pthread_create(&clntThread[loginUser], NULL, thread_main,
                           (void *)&clntSock) != 0)
            errorHandler("Pthread_create");
	

        pthread_mutex_lock(&mutex);
        loginUser++;
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
