#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
    pid_t child1, child2;
    int status1, status2;
    child1 = fork();
    if (child1 < 0) {
        printf("First fork failed.\n");
        return 1;
    }
    if (child1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        exit(5);
    }
    child2 = fork();
    if (child2 < 0) {
        printf("Second fork failed.\n");
        return 1;
    }
    if (child2 == 0) {
        printf("Child 2 PID: %d\n", getpid());
        exit(10);
    }
    printf("Parent PID: %d\n", getpid());
    waitpid(child2, &status2, 0);
    if (WIFEXITED(status2)) {
        printf("Child 2 finished with exit status: %d\n",
               WEXITSTATUS(status2));
    }
    wait(&status1);
    if (WIFEXITED(status1)) {
        printf("Child 1 finished with exit status: %d\n",
               WEXITSTATUS(status1));
    }
    return 0;
}
