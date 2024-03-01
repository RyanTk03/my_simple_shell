#ifndef IO_H
#define IO_H

#define BUFFER_SIZE 4096


ssize_t getline(char **lineptr, ssize_t *n, FILE *stream);
int printline(char *str, int fd);
int printstr(char *str, int fd);

#endif /* IO_H */
