#include <stddef.h>
#include <stdlib.h>

#include "dict.h"
#include "mystring.h"


/**
 * createDictItem - create a dictionnary key, value item
 *
 * @key: the key of the new element
 * @value: the value of the new element
 *
 * Return: the new dictionnary item created
 */
dictItem_t *createDictItem(char *key, char *value)
{
	if (key)
	{
		dictItem_t *item = malloc(sizeof(dictItem_t));

		if (item)
		{
			if (mystrset(key, &item->key))
			{
				if (mystrset(value, &item->value))
				{
					item->next = NULL;
					return (item);
				}
				free(item->key);
			}
			free(item);
		}
		return (NULL);
	}
	return (NULL);
}


/**
 * deleteDictItem - delete an item in the dictionnary
 *
 * @dict: the dictionnary from where to delete the item
 * @item: the item to delete
 */
void deleteDictItem(dict_t *dict, dictItem_t *item)
{
	if (dict && dict->head && item)
	{
		dictItem_t *current = dict->head, *last = dict->head;

		while (current && current != item)
		{
			last = current;
			current = current->next;
		}
		if (current)
		{
			if (current == dict->head)
				dict->head = current->next;
			else
				last->next = current->next;

			free(current->key);
			free(current->value);
			free(current);
			dict->len--;
		}
	}
}


/**
 * setDictValue - set a value of a key in the dict.
 * Change the value of a key if the key already exists in the dictionnary.
 * If not, create a new new node and add it to the dict.
 *
 * @dict: the dictionnary
 * @key: the key which value to set
 * @value: the value of the key
 *
 * Return: the pointer to the node of the key modified
 */
dictItem_t *setDictValue(dict_t *dict, char *key, char *value)
{
	if (dict != NULL)
	{
		dictItem_t *current = dict->head;
		char find = 0;

		while (current)
		{
			if (mystrcmp(current->key, key) == 0)
				find = 1;
		}

		if (find)
		{
			mystrset(value, &current->value);
			return (current);
		}
		else
		{
			dictItem_t *newNode = createDictItem(key, value);

			if (newNode)
			{
				if (!dict->head)
					dict->head = newNode;
				else
					current->next = newNode;
				dict->len++;
				return (newNode);
			}
		}
	}
	return (NULL);
}


/**
 * getDictValue - get the value of a key in the dictionnary
 *
 * @dict: the dict where search for the key
 * @key: the key which value to get
 * @value: a pointer to a string which will contain the value of the key
 *
 * Return: the node(dictItem) where the key where found
 */
dictItem_t *getDictValue(dict_t *dict, char *key, char **value)
{
	if (dict && key)
	{
		dictItem_t *current = dict->head;

		while (current)
		{
			if (mystrcmp(current->key, key) == 0)
			{
				if (value)
					*value = current->value;
				return (current);
			}
			current = current->next;
		}
	}
	return (NULL);
}


/**
 * freeDict - free a dictionnary
 *
 * @dict: a poiter to the dictionnary to free
 */
void freeDict(dict_t *dict)
{
	if (dict)
	{
		dictItem_t *current = dict->head, *last = NULL;

		last = current;
		while (current)
		{
			deleteDictItem(dict, last);
			last = current->next;
			current = current->next;
		}

		free(dict);
	}
}
