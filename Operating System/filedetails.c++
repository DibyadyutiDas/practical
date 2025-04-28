#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last access time: %s", ctime(&fileStat.st_atime));
    return 0;
}