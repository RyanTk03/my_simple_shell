#include <unistd.h>
#include <stdlib.h>

#include "io.h"
#include "mystring.h"


/**
 * printline - print a line to the screen
 *
 * @str: the string to print
 * @fd: the file descriptor
 *
 * Return: the amount of charactere read
 */
int printline(char *str, int fd)
{
	int i = write(fd, str, mystrlen(str));

	i += write(fd, "\n", 1);
	return (i);
}


/**
 * printstr - print a string of charactere to the screen
 *
 * @str: the string to print
 * @fd: the file descriptor
 *
 * Return: the amount of charactere read
 */
int printstr(char *str, int fd)
{
	return (write(fd, str, mystrlen(str)));
}


/**
 * mygetline - get a line from the program input
 *
 * @lineptr: a pointer to the buffer to fill
 * @fd: the file descriptor to use
 *
 * Return: the amount of charactere reads
 */
ssize_t mygetline(char *lineptr, int fd)
{
	if (!lineptr)
		return (-1); /* Invalid arguments */

	return (read(fd, lineptr, BUFFER_SIZE));
}

