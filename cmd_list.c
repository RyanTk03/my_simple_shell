#include "shell.h"
#include "cmd_list.h"


/**
 * initCmdList - init the list of command.
 *
 * @cmds: The adress to the pointer of the list of command.
 *
 * Return: 1 if the list of command were correctly initialized and 0 else.
 */
int initCmdList(cmdList_t **cmds)
{
	if (cmds)
	{
		if (!*cmds)
			*cmds = malloc(sizeof(cmdList_t));

		if (*cmds)
		{
			*cmds->len = 0;
			*cmds->current = 0;
			*cmds->first = NULL;
			return (1);
		}
	}

	return (0);
}


/**
 * appendCmd -  adds a new node at the beginning of a cmd_t list.
 *
 * @cmds: the list where add the node
 * @newCmd: the new command to add
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *appendCmd(cmdList_t *cmds, cmd_t *newCmd)
{
	if (newCmd)
	{
		newCmd->next = NULL;
		if (!cmds->first)
		{
			cmds->first = newCmd;
			return (cmds->first);
		}
		cmd_t *current = cmds->first;

		while (current->next)
			current = current->next;

		current->next = newCmd;
	}
	newCmd->len = strlen(str);
	newCmd->next = *head;

	*head = newCmd;

	return (newCmd);
}


/**
 * initCmd - init a command.
 *
 * @cmd: The adress to the pointer of a command.
 *
 * Return: 1 if the the command were correctly initialized and 0 else.
 */
int initCmd(cmd_t **cmd)
{
	if (cmd)
	{
		if (!*cmd)
			*cmd = malloc(sizeof(cmd_t));

		if (*cmd)
		{
			(*cmd)->args = NULL;
			(*cmd)->op = OP_NONE;
			(*cmd)->next = NULL;
			return (1);
		}
	}

	return (0);
}


/**
 * freeCmd - free memory allocated for a cmd_t element.
 *
 * @cmd: The command to free.
 */
void freeCmd(cmd_t *cmd)
{
	if (cmd)
		free(cmd);
}


/**
 * freeCmdList - free memory allocated for the commands list.
 *
 * @cmds: The commands list to free.
 */
void freeCmdList(cmdList_t *cmds)
{
	if (cmds)
	{
		cmd_t *current = cmds->first;

		while (current)
		{
			cmd_t *toDelete = current;

			current = current->next;
			freeCmd(toDelete);
		}

		free(cmds);
	}
}

