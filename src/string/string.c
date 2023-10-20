// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	if (!destination)
		return NULL;
	char *ptr = destination;
	while (*source != 0) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (!destination)
		return NULL;
	if (len == 0)
		return destination;
	char *ptr = destination;
	size_t n = 0;
	while (*source != 0 && n <= len) {
		*destination = *source;
		destination++;
		source++;
		n++;
	}
	*destination = '\0';

	return ptr;
}

char *strcat(char *destination, const char *source)
{
	char *ptr = destination + strlen(destination);
	while (*source != '\0') {
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *ptr = destination + strlen(destination);
	size_t n = 0;
	while (*source != '\0' && n < len) {
		*ptr = *source;
		ptr++;
		source++;
		n++;
	}
	*ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' || *str2 != '\0') {
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t n = len;
	if (n == 0)
		return 0;
	while (n) {
		n--;
		if (*str1 == 0 || *str2 == 0)
			break;
		if (*str1 != *str2)
			return *str1 - *str2;
		str1++;
		str2++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == c)
			return str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *found = NULL;
	while (*str) {
		if (*str == c)
			found = str;
		*str++;
	}
	return found;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}
