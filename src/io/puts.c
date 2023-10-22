#include <stdio.h>
#include <errno.h>
#include <unistd.h>

// puts source: https://chat.openai.com/
int puts(const char* str)
{
    int written = 0;

    while (str[written] != '\0') {
        if (write(1, &str[written], 1) != 1) {
            return -1;
        }
        written++;
    }

    if (write(1, "\n", 1) != 1) {
        return -1;
    }

    return written + 1;
}
