#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <stdlib.h>
#include <string.h>

/**
 * struct List - List to be used by the hashtable
 * @key : The key string of a pair
 * The key is unique in the HashTable
 * @value : The value corresponding to a key
 * A value is not unique. It can correspond to several keys
 * @next : A pointer to the next node of the List
 */
typedef struct List
{
	char *key;
	char *value;
	struct List *next;
} List;

/**
 * struct HashTable - HashTable using a  Chaining collision handling
 * @size : The size of the array
 * @array : An array of size @size
 *
 * Description: Each cell of this array is a pointer to the first node
 * of a linked list, because we want our HashTable to
 * use a Chaining collision handling
 */
typedef struct HashTable
{
	unsigned int size;
	struct List **array;
} HashTable;

unsigned int hash(const char *key, unsigned int size);
HashTable *ht_create(unsigned int size);
int ht_put(HashTable *hashtable, const char *key, const char *value);
char *ht_get(HashTable *hashtable, const char *key);
void ht_free(HashTable *hashtable);

#define INITIAL_TABLE_SIZE 30
#endif
