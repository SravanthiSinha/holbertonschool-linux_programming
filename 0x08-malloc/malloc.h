#ifndef _MALLOC_H
#define _MALLOC_H

#include <unistd.h>
#include <stdio.h>

#define PAGE_SIZE ((size_t) sysconf(_SC_PAGESIZE))
#define align8(x) (((((x) - 1) >> 2) << 2) + 8)

typedef struct s_block *t_block;

/**
* struct s_block - Holds the details of each block
* @size: size of block
* @next: pointer to next block
* @free: 1 if block is free else 0
* @data: data stored at the block
*/
struct s_block
{
	size_t size;
	t_block next;
	int free;
	char data[1];
};

#define BLOCK_SIZE sizeof(struct s_block)

void *naive_malloc(size_t size);
void *_malloc(size_t size);

#endif
