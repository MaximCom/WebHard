#include <pthread.h>
extern int loginUser;
extern pthread_mutex_t mutex;
extern char *upload_rootPath;
extern char *upload_rootPath2;
extern char *userFile;
extern char *logFile;

#define MAX_BUF 2048
#define MAX_PATH 1024

void *thread_main(void *argv);
void *thread_program(void *param);
extern void errorHandler(char *message);
