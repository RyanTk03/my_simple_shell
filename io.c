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
}
	int i = write(fd, str, mystrlen(str));

	i += write(fd, '\n', 1);
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
}
	return (write(fd, str, mystrlen(str)));
}


/**
 * getline - get a line from the program input
 *
 * @lineptr: a pointer to the buffer to fill
 * @n: a pointer that will be filled with the size of the buffer
 * @stream: the stream to read
 *
 * Return: the amount of charactere reads
 */
ssize_t getline(char **lineptr, ssize_t *n, FILE *stream)
{
	if (!lineptr || !n || !stream)
		return (-1); /* Invalid arguments */

	size_t bufsize = 0;
	char *buffer = NULL;
	int c;
	ssize_t len = 0;

	while ((c = fgetc(stream)) != EOF)
	{
		if (len >= bufsize)
		{
			char *new_buffer = realloc(buffer, bufsize + 128);

			bufsize += 128; /* Increase buffer size */
			if (!new_buffer)
			{
				free(buffer);
				return (-1); /* Memory allocation failed */
			}
			buffer = new_buffer;
		}

		buffer[len++] = c;

		if (c == '\n')
			break; /* End of line */
	}

	if (len == 0)
		return (-1); /* No data reads */

	buffer[len] = '\0'; /* Null-terminate the string */
	*lineptr = buffer;
	*n = len;

	return (len);
}

