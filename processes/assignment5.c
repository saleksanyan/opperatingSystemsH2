#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        _exit(0);
    } else if (pid > 0) {
        printf("Parent process: PID = %d\n", getpid());
        sleep(10);
    } else {
        printf("Fork failed\n");
    }
    return 0;
}
