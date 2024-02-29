#ifndef MYSTRING_H
#define MYSTRING_H

int mystrlen(char *s);
int mystrcmp(char *s1, char *s2);
int mystrcopy(char *src, char *dst, int from, int len);
char *mystrset(char *src, char **dst);
char *mystrchr(char *s, int c);

#endif /* MYSTRING_H */
