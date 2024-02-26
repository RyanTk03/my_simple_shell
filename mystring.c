#include "mysting.h"

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
 * mystrcopy - copy a part of string from an index to another string
 * @src: the string to copy
 * @dst: the destination where copy the string
 * @from: the starting index
 * @len: the number of charactere to copy
 *
 * Return: pointer to the destination string
 */
char *mystrcopy(char *src, char *dst, int from, int len)
{
	char *ret = dest;
	int i = 0;

	for (i = from; i <= from + len; i++)
	{
		*dest = src[i];
		dest++;
	}

	return (ret);
}

