#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();

    if (pid1 == 0) {
        printf("First child process PID: %d\n", getpid());
        _exit(10);
    } else if (pid1 > 0) {
        pid2 = fork();

        if (pid2 == 0) {
            printf("Second child process PID: %d\n", getpid());
            _exit(20);
        } else if (pid2 > 0) {
            printf("Parent process PID: %d\n", getpid());

            waitpid(pid1, &status, 0);
            if (WIFEXITED(status)) {
                printf("First child exited with status %d\n", WEXITSTATUS(status));
            }

            waitpid(pid2, &status, 0);
            if (WIFEXITED(status)) {
                printf("Second child exited with status %d\n", WEXITSTATUS(status));
            }
        } else {
            printf("Fork failed for second child\n");
        }
    } else {
        printf("Fork failed for first child\n");
    }

    return 0;
}
