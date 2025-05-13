#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *proc = opendir("/proc");
    struct dirent *entry;

    if (!proc) {
        perror("opendir /proc");
        return 1;
    }

    while ((entry = readdir(proc)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid <= 0) continue;

            char cmdline_path[256];
            snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/comm", pid);

            FILE *cmdline = fopen(cmdline_path, "r");
            if (!cmdline) continue;

            char name[256];
            if (fgets(name, sizeof(name), cmdline)) {
                if (strncmp(name, "top", 3) == 0) {
                    fclose(cmdline);

                    char status_path[256];
                    snprintf(status_path, sizeof(status_path), "/proc/%d/status", pid);
                    FILE *status = fopen(status_path, "r");
                    if (!status) continue;

                    char line[256];
                    while (fgets(line, sizeof(line), status)) {
                        if (strncmp(line, "PPid:", 5) == 0) {
                            printf("Parent PID of 'top' (PID %d): %s", pid, line + 6);
                            break;
                        }
                    }

                    fclose(status);
                    break;
                }
            }

            fclose(cmdline);
        }
    }

    closedir(proc);
    return 0;
}
