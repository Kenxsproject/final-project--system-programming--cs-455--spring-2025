#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filepath = "README.md";
    const char *target = "### Program 3";
    const char *replacement = "### PROGRAM 3";
    char buffer[4096];

    int fd = open(filepath, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    // Look for the string
    char *pos = strstr(buffer, target);
    if (pos == NULL) {
        printf("String '### Program 3' not found.\n");
        close(fd);
        return 1;
    }

   
    off_t offset = pos - buffer;

    // Move the write pointer
    if (lseek(fd, offset, SEEK_SET) < 0) {
        perror("lseek");
        close(fd);
        return 1;
    }

    // Write the replacement
    if (write(fd, replacement, strlen(replacement)) < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("'### Program 3' replaced with '### PROGRAM 3'\n");
    close(fd);
    return 0;
}
