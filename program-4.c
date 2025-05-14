#include <stdio.h>
#include <stdlib.h>


extern char _etext;  // End of program text segment
extern char _edata;  // End of initialized data segment
extern char _end;    // End of uninitialized data segment 

int main() {
    // Dynamically allocate 1024 bytes
    char *buffer = (char *)malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    // Display segment addresses
    printf("End of program text (etext):      %p\n", &_etext);
    printf("End of initialized data (edata):  %p\n", &_edata);
    printf("End of uninitialized data (end):  %p\n", &_end);

    // Clean up
    free(buffer);
    return 0;
}
