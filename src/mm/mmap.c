// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	int valid_flags = MAP_SHARED | MAP_ANONYMOUS | MAP_PRIVATE;

	if ((flags == MAP_ANONYMOUS) || (flags & ~valid_flags) != 0) {
		errno = EINVAL; // Bad flags
		return MAP_FAILED;
	}

	if (!(flags & MAP_ANONYMOUS)) {
        if (fd < 0 || (flags & MAP_SHARED )) {
            errno = EBADF;  // Bad file descriptor
            return MAP_FAILED;
        }
    }

    long result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    if (result < 0) {
        return MAP_FAILED;
    }

    return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long result = syscall(__NR_mremap, old_address, old_size, new_size, flags);
    if (result < 0) {
        return MAP_FAILED;
    }

    return (void *)result;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	long result = syscall(__NR_munmap, addr, length);
    if (result < 0) {
        return (__INTPTR_TYPE__)MAP_FAILED;
    }

    return result;
	return -1;
}
