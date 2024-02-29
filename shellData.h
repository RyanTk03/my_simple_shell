#ifndef SHELL_DATA_H
#define SHELL_DATA_H

#include "dict.h"
#include "list.h"

/**
 * struct shellData_s - contains the current instance of shell data
 *
 * @cmdsHead: the list of commands to excecute
 * @alias: the shell alias
 * @env: the environment's variable of the program
 * @PATH: the path
 * @cwd: the current working dir
 * @argv: the shell arguments
 */
typedef struct shellData_s
{
	cmd_t *cmdsHead;
	dict_t *alias;
	dict_t *env;
	list_t *PATH;
	char *cwd;
	char **argv;
} shellData_t;

void initShellData(shellData_t *data, char **argv, char **env);

#endif /* SHELL_DATA_H */
