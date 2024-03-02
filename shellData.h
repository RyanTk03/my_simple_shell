#ifndef SHELL_DATA_H
#define SHELL_DATA_H

#include "dict.h"
#include "list.h"
#include "cmd.h"

/**
 * struct shellData_s - contains the current instance of shell data
 *
 * @isInteractive: boolean value that indicate if the shell is interactive
 * @cmdsHead: the list of commands to excecute
 * @alias: the shell alias
 * @env: the environment's variable of the program
 * @PATH: the path
 * @cwd: the current working dir
 * @argc: the number of arguments receives by the shell
 * @argv: the shell arguments
 * @quit: indicate if the shell should be exit or not
 * @exitStatus: the status of the exit or last command executed
 */
typedef struct shellData_s
{
	int isInteractive;
	cmd_t *cmdsHead;
	dict_t *alias;
	dict_t *env;
	list_t *PATH;
	char *cwd;
	char **argv;
	int argc;
	int quit;
	int exitStatus;
} shellData_t;

void initShellData(shellData_t *data, int argc, char **argv, char **env);
void resetShellData(shellData_t *shData);
void freeShellData(shellData_t *shData);
int replaceAlias(shellData_t *shData, char **src);

#endif /* SHELL_DATA_H */
