#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }
    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (src < 0 || dest < 0) {
        perror("Error opening files");
        return 1;
    }
    char buffer[1024];
    ssize_t bytes;
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }
    close(src);
    close(dest);
    return 0;
}