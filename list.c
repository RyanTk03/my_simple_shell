#include "lists.h"

/**
 * printList - Prints all the elements of a list_t list.
 *
 * @h: The head of the list.
 * Return: the number of nodes.
 */
size_t printList(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		printline(h->value, STDOUT_FILENO);
		h = h->next;
		n++;
	}
	return (n);
}


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
 * free_list - frees a list_t list.
 *
 * @head: the head of the list.
 */
void free_list(list_t *head)
{
	list_t *toDel = NULL;

	while (head)
	{
		toDel = head;
		head = head->next;
		free(toDel->str);
		free(toDel);
	}
}

