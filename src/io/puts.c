#include <stdio.h>
#include <errno.h>

int puts(const char* str)
{
    int written = 0;

    while (str[written] != '\0') {
        if (write(1, &str[written], 1) != 1) {
            return -1; // Error occurred
        }
        written++;
    }

    if (write(1, "\n", 1) != 1) {
        return -1; // Error occurred while writing the newline character
    }

    return written + 1; // Success
}