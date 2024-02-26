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
 * @op: the operator used between a command and the next
 * @prog: a string that contains the name of the programme or script to execute
 * @args: a string that contains the arguments to send to the program
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


/**
 * struct cmdList_s - the command list object
 * @len: the length of the list
 * @current: the current command that is executed
 * @first: the first element/node of the list
 *
 * Description: structure for the list of command
 */
typedef struct cmdList_s
{
	int len;
	int current;
	cmd_t *first;
} cmdList_t;

int initCmdList(cmdList_t *cmds);
int initCmd(cmd_t *cmd);
cmd_t *appendCmd(cmdList_t *cmds, cmd_t *newCmd);
void freeCmd(cmd_t *cmd);
void freeCmdList(cmdList_t *cmds);

#endif /* CMD_LIST_H_INCLUDED */
