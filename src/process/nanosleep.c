#include <internal/syscall.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int result = syscall(__NR_nanosleep, req, rem);
    if (result < 0)
        return -1;
    return result;
}
