#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void test_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    printf("Testing file: %s\n", filename);
    char *line;
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }
    printf("Total lines read: %d\n\n", line_count);
    close(fd);
}

int main() {
    // Good scenarios
    test_file("file1.txt");
    test_file("file2.txt");
    test_file("file3.txt");
    test_file("normal.txt");
    test_file("empty.txt");
    test_file("one_line.txt");

    // Error scenarios
    test_file("nonexistent.txt");
    test_file("/etc/passwd");  // Typically not readable, tests permission denied

    // Test with stdin
    printf("Enter some text (Ctrl+D to end):\n");
    char *stdin_line;
    while ((stdin_line = get_next_line(0)) != NULL) {
        printf("You entered: %s", stdin_line);
        free(stdin_line);
    }

    // Test with invalid fd
    char *invalid_fd_line = get_next_line(-1);
    if (invalid_fd_line == NULL) {
        printf("Correctly handled invalid fd\n");
    } else {
        printf("Failed to handle invalid fd\n");
        free(invalid_fd_line);
    }

    return 0;
}
