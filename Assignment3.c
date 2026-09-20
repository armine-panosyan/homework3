#include <stdio.h>
#include <stdlib.h>

void firstCleanup() {
    printf("First cleanup\n");
}
void secondCleanup() {
    printf("Second cleanup\n");
}
int main() {
    atexit(firstCleanup);
    atexit(secondCleanup);
    printf("Program is running\n");
    printf("Exiting program\n");
    exit(0);
    return 0;
}
