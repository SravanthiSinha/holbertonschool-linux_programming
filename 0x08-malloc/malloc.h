#ifndef _MALLOC_H
#define _MALLOC_H

#include <unistd.h>
#include <stdio.h>

#define PAGE_SIZE ((size_t) sysconf(_SC_PAGESIZE))
#define align8(x) ((x % 8) ? (x + (8 - x % 8)) : x)

typedef struct s_block *t_block;

/**
* struct s_block - Holds the details of each block
* @size: size of block
* @next: pointer to next block
*/
struct s_block
{
	size_t size;
	struct s_block *next;
};

#define BLOCK_SIZE sizeof(struct s_block)

void *naive_malloc(size_t size);
void *_malloc(size_t size);

#endif
