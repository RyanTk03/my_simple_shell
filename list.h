#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @value: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *value;
	unsigned int len;
	struct list_s *next;
} list_t;

list_t *appendList(list_t **head, const char *str);
void freeList(list_t *head);

#endif /* LISTS_H_INCLUDED */
