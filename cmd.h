#ifndef CMD_LIST_H_INCLUDED
#define CMD_LIST_H_INCLUDED

#include <stdio.h>

#define MAX_BUFFER_SIZE 4096

#define OP_NONE 0
#define OP_AND 1
#define OP_OR 2
#define OP_SEP 3
#define OP_COM 4
/* Not needed for this project but maybe will add this feature later */
#define OP_PIPE 5
#define OP_AMPERSAND 6


/**
 * struct cmd_s - a command node
 * @op: the operator used before the next command
 * @args: a vector of string of the arguments to send to the program/command
 * with args[0] the program/command to execute.
 * @next: point to the next node
 *
 * Description: singly linked list node structure for a command
 */
typedef struct cmd_s
{
	char op;
	char **args;
	cmd_t *next;
} cmd_t;


int initCmd(cmd_t *cmd);
cmd_t *appendCmd(cmd_t **head, cmd_t *newCmd);
void freeCmd(cmd_t *cmd);
void freeCmds(cmdList_t *cmds);

#endif /* CMD_LIST_H_INCLUDED */
