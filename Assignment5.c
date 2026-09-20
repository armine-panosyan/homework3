#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        exit(0);
    } else {
        printf("Parent PID: %d\n", getpid());
        printf("Child finished, parent is still running\n");
        sleep(30);
    }
    return 0;
}
