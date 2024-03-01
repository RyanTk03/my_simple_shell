#include <stddef.h>
#include <stdlib.h>

#include "mystring.h"

/**
 * mystrlen - returns the length of a string
 * @s: the string whose length to get
 *
 * Return: the length of the string get in param
 */
int mystrlen(char *s)
{
	if (s)
	{
		int i = 0;

		while (*s++)
			i++;
		return (i);
	}

	return (0);
}


/**
 * mystrcmp - compare two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: -1 if s1 < s2, 1 if s1 > s2, zero if s1 == s2
 */
int mystrcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 < *s2 ? -1 : 1);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


/**
 * mystrncpy - copy a part of string from an index to another string
 * @src: the string to copy
 * @dst: the destination where copy the string
 * @from: the starting index
 * @len: the number of charactere to copy
 *
 * Return: the amount of charactere copied
 */
int mystrncpy(char *src, char *dst, int from, int len)
{
	int i = 0;

	for (i = from; i < from + len && src[i]; i++)
	{
		*dst = src[i];
		dst++;
	}

	return (i);
}


/**
 * mystrset - affect the content of a source string to a destination string
 *
 * @src: the value to set
 * @dst: point to the string to fill
 *
 * Return: the pointer to the new string affected
 */
char *mystrset(char *src, char **dst)
{
	if (src && dst)
	{
		int len = mystrlen(src), i = 0;

		if (*dst)
			free(*dst);
		*dst = malloc(sizeof(char) * (len + 1));
		if (*dst)
		{
			while (src[i])
			{
				(*dst)[i] = src[i];
				i++;
			}
			(*dst)[i] = '\0';

			return (*dst);
		}
	}
	return (NULL);
}


/**
 * mystrstartsWith - checks if s1 starts with s2
 * @s1: string to search
 * @s2: the substring to find
 *
 * Return: address of next char of s1 or NULL
 */
char *mystrstartsWith(const char *s1, const char *s2)
{
	while (*s2)
		if (*s2++ != *s1++)
			return (NULL);
	return ((char *)s1);
}

