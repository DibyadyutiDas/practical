#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process executing.\n");
    } else if (pid > 0) {
        printf("Parent process executing.\n");
    } else {
        perror("Fork failed");
    }
    return 0;
}