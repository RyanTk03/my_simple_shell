#include <stddef.h>

#include "mystring.h"


/**
 * mystrchr - search a charactere in the string s
 *
 * @s: the string where search the charactere
 * @c: the charactere to search
 *
 * Return: the pointer to the charactere find or NULL
 */
char *mystrchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
