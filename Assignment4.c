#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;
    int status1, status2;
    child1 = fork();
    if (child1 == 0) {
        printf("Child 1 started\n");
        exit(0);
    }
    child2 = fork();
    if (child2 == 0) {
        printf("Child 2 started\n");
        exit(2);
    }
    waitpid(child1, &status1, 0);
    waitpid(child2, &status2, 0);

    if (WIFEXITED(status1)) {
        int code1 = WEXITSTATUS(status1);

        printf("Child 1 exit code: %d\n", code1);

        if (code1 == 0) {
            printf("Child 1 exited normally\n");
        } else {
            printf("Child 1 exited with an error\n");
        }
    }
    if (WIFEXITED(status2)) {
        int code2 = WEXITSTATUS(status2);
        printf("Child 2 exit code: %d\n", code2);
        if (code2 == 0) {
            printf("Child 2 exited normally\n");
        } else {
            printf("Child 2 exited with an error\n");
        }
    }
    return 0;
}
