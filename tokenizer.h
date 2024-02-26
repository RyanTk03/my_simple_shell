#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "cmd_list.h"

char getCharType(char *str, int *current);
void gotoNextNotSpace(char *str, int *current);
cmd_t *tokenize(char *src);

#endif /* TOKENIZER_H */
