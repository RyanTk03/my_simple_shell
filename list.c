#include "list.h"


/**
 * appendList - adds a new node at the end of a list_t list.
 *
 * @head: the head of the list
 * @str: the string value
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *appendList(list_t **head, const char *str)
{
	list_t *nl = malloc(sizeof(list_t));
	list_t *l = *head;

	if (!nl)
		return (NULL);

	nl->value = strdup(str);
	nl->len = strlen(str);
	nl->next = NULL;

	while (l && l->next)
		l = l->next;

	if (!l)
		*head = nl;
	else
		l->next = nl;

	return (nl);
}


/**
 * freeList - frees a list_t list.
 *
 * @head: the head of the list.
 */
void freeList(list_t *head)
{
	list_t *toDel = NULL;

	while (head)
	{
		toDel = head;
		head = head->next;
		free(toDel->value);
		free(toDel);
	}
}

