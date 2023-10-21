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
	while (*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;
		while (*h == *n && *n != 0) {
			h++;
			n++;
		}
		if (*n == '\0')
			return haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *found = NULL;
	while (*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;
		while (*h == *n && *n != 0) {
			h++;
			n++;
		}
		if (*n == '\0')
			found = haystack;
		haystack++;
	}
	return found;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *cdest = (char *) destination;
	char *csrc = (char *) source;
	for (int i = 0; i < num; i++) {
		cdest[i] = csrc[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)	
{
	char *cdest = (char *) destination;
	char *csrc = (char *) source;
	char aux[num];
	for (size_t i = 0; i < num; i++)
		aux[i] = csrc[i];
	memcpy(destination, aux, num);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char cptr1;
	unsigned char cptr2;
	while (num-- > 0) {
		cptr1 = * (unsigned char *)ptr1;
		cptr2 = * (unsigned char *)ptr2;
		if (cptr1 != cptr2)
		return (cptr1 - cptr2);
		ptr1++;
		ptr2++;
	}
	
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *cs = (unsigned char *) source;
	for (size_t i= 0; i < num; i++) {
		cs[i] = (unsigned char) value;
	}
	return source;
}
