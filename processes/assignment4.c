#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 == 0){
        exit(10);
    } else if (pid1 > 0) {
        pid2 = fork();

        if (pid2 == 0) {
            exit(20);
        } else if (pid2 >0) {
            printf("Parent process PID: %d\n", getpid());

            waitpid(pid1, &status, 0);
            if (WIFEXITED(status)) {
                printf("First child exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("First child did not exit normally\n");
            }

            waitpid(pid2, &status, 0);
            if (WIFEXITED(status)) {
                printf("Second child exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Second child did not exit normally\n");
            }
        }
    }

    return 0;
}
