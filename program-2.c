//In C, the third argument to main is char *envp[],an array of strings that represent the environment variables available to the process.
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("Reading environment variables from envp[]:\n\n");

    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "SHELL=", 6) == 0 ||
            strncmp(envp[i], "PATH=", 5) == 0 ||
            strncmp(envp[i], "USERNAME=", 9) == 0 ||
            strncmp(envp[i], "USER=", 5) == 0) {
            printf("%s\n", envp[i]);
        }
    }

    return 0;
}

