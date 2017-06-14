#include "hls.h"

/**
  * hash - Creates the hash for a key based on the size of the array and
  * the key value.
  * @key: The key whose hash has to be computed.
  * @size: The array size of hashtable.
  *
  * Return: Hash of the key.
  */
unsigned int hash(const char *key, unsigned int size)
{
	unsigned int hash;
	unsigned int i;

	hash = 0;
	i = 0;
	while (key && key[i])
	{
		hash = hash + key[i];
		++i;
	}
	hash = hash % size;
	return (hash);
}

/**
  * ht_create - Creates the hashtable with definite array size.
  * @size: The array size of hashtable.
  *
  * Return: on success: Hahtable built , on Failure: NULL.
  */
HashTable *ht_create(unsigned int size)
{
	HashTable *hashtable;
	unsigned int i;

	hashtable = malloc(sizeof(HashTable));
	if (hashtable == NULL)
		return (NULL);
	hashtable->size = size;
	hashtable->array = malloc(size * (sizeof(List)));
	if (hashtable->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hashtable->array[i] = NULL;
	return (hashtable);
}

/**
  * ht_put - Puts/add the value in the hashtable for a key.
  * @hashtable: The hashtable to be added in.
  * @key: The hash(key) to be inserted in hashtable.
  * @value: The value to be inserted in hashtable for hash(key).
  *
  * Return: on success: HLS_SUCCESS - 0 , on Failure: HLS_MAJOR_ERROR -2.
  */
int ht_put(HashTable *hashtable, const char *key, const char *value)
{
	unsigned int hashcode;
	List *head;
	List *temp;

	hashcode = hash(key, hashtable->size);
	head = hashtable->array[hashcode];
	temp = malloc(sizeof(List));

	if (temp != NULL)
	{
		temp->key = strdup(key);
		temp->value = strdup(value);
		temp->next = head;
		hashtable->array[hashcode] = temp;
		return (HLS_SUCCESS);
	}
	return (HLS_MAJOR_ERROR);
}

/**
  * ht_get - Gets the value stored in the hashtable for a key.
  * @hashtable: The hashtable to be looked in.
  * @key: The key to be looked in hashtable.
  *
  * Return: the value represented by key in the hashtable.
  */
char *ht_get(HashTable *hashtable, const char *key)
{
	unsigned int hashcode;
	List *head;
	List *node;

	hashcode = hash(key, hashtable->size);
	head = hashtable->array[hashcode];
	node = head;
	while (node)
	{
		if (hash(node->key, hashtable->size) == hashcode)
			if (strcmp(node->key, key) == 0)
				return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
  * ht_free - Frees the hashtable
  * @hashtable: The hashtable to be freed
  *
  * Return: void
  */
void ht_free(HashTable *hashtable)
{
	unsigned int i;
	List *node;
	List *temp;

	node = NULL;
	temp = NULL;
	if (hashtable != NULL)
	{
		if (hashtable->array)
		{
			for (i = 0; i < hashtable->size; i++)
			{
				node = hashtable->array[i];
				while (node != NULL)
				{
					free(node->key);
					free(node->value);
					temp = node;
					node = node->next;
					free(temp);
				}
			}
			free(hashtable->array);
		}
		free(hashtable);
	}
}
