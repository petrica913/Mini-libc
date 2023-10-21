// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

struct mem_list new_mem_list;

void *malloc(size_t size)
{
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	new_mem_list.len = size;
	new_mem_list.start = &ptr;
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	void *ptr = malloc(total_size);
	if (ptr) {
		unsigned char *byte = (unsigned char *)ptr;
		for (size_t i = 0; i < total_size; i++)
			byte[i] = 0;
	}
	return ptr;
}

void free(void *ptr)
{
	return munmap(ptr, new_mem_list.len);
}

void *realloc(void *ptr, size_t size)
//probleme si aici pica testul de accesare al datelor
{
	void *result = mremap(&ptr, new_mem_list.len, size, MREMAP_MAYMOVE);
	new_mem_list.len = size;
	return result;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return NULL;
}
