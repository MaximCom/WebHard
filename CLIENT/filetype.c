#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char fileType(const struct stat *fileInfo) {
    char c;
    if (S_ISREG(fileInfo->st_mode)) {
        return '-';
    } else if (S_ISDIR(fileInfo->st_mode)) {
        return 'd';
    } else if (S_ISLNK(fileInfo->st_mode)) {
        return 'l';
    } else if (S_ISSOCK(fileInfo->st_mode)) {
        return 's';
    } else if (S_ISFIFO(fileInfo->st_mode)) {
        return '?';
    } else if (S_ISCHR(fileInfo->st_mode)) {
        return 'c';
    } else if (S_ISBLK(fileInfo->st_mode)) {
        return 'b';
    } else if (S_TYPEISMQ(fileInfo)) {
        return '?';

    } else if (S_TYPEISSEM(fileInfo)) {
        return '?';
    } else if (S_TYPEISSHM(fileInfo)) {
        return '?';
    }
    return '?';
}
