#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

#define MAX_FILES 4

void test_multiple_files(const char *filenames[]) {
    int fds[MAX_FILES];
    int open_files = 0;

    // Open all files
    for (int i = 0; i < MAX_FILES && filenames[i] != NULL; i++) {
        fds[i] = open(filenames[i], O_RDONLY);
        if (fds[i] == -1) {
            printf("Error opening file: %s\n", filenames[i]);
        } else {
            open_files++;
            printf("Opened file: %s (fd: %d)\n", filenames[i], fds[i]);
        }
    }

    // Read from files alternately
    int completed = 0;
    while (completed < open_files) {
        for (int i = 0; i < open_files; i++) {
            char *line = get_next_line(fds[i]);
            if (line) {
                printf("File %d: %s", i, line);
                free(line);
            } else {
                printf("File %d: EOF reached\n", i);
                close(fds[i]);
                fds[i] = -1;
                completed++;
            }
        }
        printf("\n");
    }
}

void test_stdin() {
    printf("Enter some text (Ctrl+D to end):\n");
    char *stdin_line;
    while ((stdin_line = get_next_line(0)) != NULL) {
        printf("You entered: %s", stdin_line);
        free(stdin_line);
    }
}

void test_invalid_fd() {
    char *invalid_fd_line = get_next_line(-1);
    if (invalid_fd_line == NULL) {
        printf("Correctly handled invalid fd\n");
    } else {
        printf("Failed to handle invalid fd\n");
        free(invalid_fd_line);
    }
}

int main() {
    const char *filenames1[] = {
        "file1.txt",
        "file2.txt",
        "file3.txt",
        NULL
    };

    const char *filenames2[] = {
        "normal.txt",
        "empty.txt",
        "one_line.txt",
        NULL
    };

    printf("Testing multiple files simultaneously:\n");
    test_multiple_files(filenames1);

    printf("Testing multiple files WITH ERRORS simultaneously:\n");
    test_multiple_files(filenames2);

    printf("\nTesting stdin:\n");
    test_stdin();

    printf("\nTesting invalid fd:\n");
    test_invalid_fd();

    return 0;
}
