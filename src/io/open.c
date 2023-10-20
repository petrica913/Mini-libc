// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	long result = syscall(__NR_open, filename, flags);
	if (result < 0) {
		errno = -result;
		return -1;
	}
	return (int) result;
}
