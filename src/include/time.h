#ifndef CUSTOM_TIME_H
#define CUSTOM_TIME_H

#include <stddef.h>

typedef long int time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

// Function to implement nanosleep
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif // CUSTOM_TIME_H
