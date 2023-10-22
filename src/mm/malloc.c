// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

#define MUL_NO_OVERFLOW	((size_t)1 << (sizeof(size_t) * 4))

struct mem_list new_mem_list;

void *malloc(size_t size)
{
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr) {
		mem_list_add(ptr, size);
		return (void *)ptr;
	} else
		return (void *)-1;
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
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	void *result = mremap(&ptr, new_mem_list.len, size, MREMAP_MAYMOVE);
	mem_list_find(ptr)->len = size;

}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0)
		return NULL;
	return realloc(ptr, nmemb * size);
}
