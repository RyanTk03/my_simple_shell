#include "printObject.h"

/**
 * printList - Prints all the elements of a list_t list.
 *
 * @h: The head of the list.
 * Return: the number of nodes.
 */
ssize_t printList(const list_t *h)
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
 * printDict - print a dictionnary on screen
 *
 * @dict: the dict to print
 *
 * Return: the amount of dict element printed
 */
ssize_t printDict(const dict_t *dict)
{
	dictItem_t *item = dict->head;
	size_t n = 0;

	while (item != NULL)
	{
		printstr(item->key, STDOUT_FILENO);
		printstr("=", STDOUT_FILENO);
		printstr(item->value, STDOUT_FILENO);
		printstr("\n", STDOUT_FILENO);
		item = item->next;
		n++;
	}
	return (n);
}
