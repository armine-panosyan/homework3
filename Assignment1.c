#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }
    if (pid == 0) {
        printf("Child process PID: %d\n", getpid());
    } else {
        printf("Parent process PID: %d\n", getpid());
    }
    return 0;
}
