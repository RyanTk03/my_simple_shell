#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "cmd.h"
#include "shellData.h"


char getCurrentCharType(char *str, int *current);
void gotoNextNotSpace(char *str, int *current);
int getNextArgLen(char *str, int i);
char *getNextArgStr(char *src, int from, int len);
cmd_t *tokenize(shellData_t *shData, char *src, int *from, int handleAlias);


#endif /* TOKENIZER_H */
