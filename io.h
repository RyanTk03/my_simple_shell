#ifndef IO_H
#define IO_H

#include "unistd.h"

#define BUFFER_SIZE 4096


ssize_t mygetline(char *lineptr, int fd);
int printline(char *str, int fd);
int printstr(char *str, int fd);

#endif /* IO_H */
