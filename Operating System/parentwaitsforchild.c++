// Parent waits for child
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork Failed\n");
    } else if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        sleep(2);
    } else {
        wait(NULL);
        printf("Parent Process: Child Finished. Parent PID = %d\n", getpid());
    }
    return 0;
}