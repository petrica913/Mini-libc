#include <internal/syscall.h>
#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req;
    req.tv_nsec = 0;
    req.tv_sec = seconds;
    nanosleep(&req, NULL);
}