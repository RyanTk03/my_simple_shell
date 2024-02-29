#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "cmd.h"


char getCurrentCharType(char *str, int *current);
void gotoNextNotSpace(char *str, int *current);
int getNextTokenLen(char *str, int i);
char *createToken(char *src, int from, int len);
cmd_t *tokenize(char *src);


#endif /* TOKENIZER_H */
