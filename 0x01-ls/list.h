#ifndef _LIST_H_
#define _LIST_H_

/**
 * struct List - List to be used to store the file options from input
 * @str : The value to be stored.
 * @next : A pointer to the next node of the List
 */
typedef struct List
{
	char *str;
	struct List *next;
} List;

List *array_to_list(char **a);
int list_size(List *list);
void free_list(List *head);
void deleteParam(List **head_ref, char *key);
char *get_node(List *head, int index);
void print_list(List *list);
int list_add(List **list, char *content);
int delete_nodeint_at_index(List **head, unsigned int index);
#endif
