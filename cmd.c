#include <stdlib.h>

#include "shell.h"
#include "cmd.h"


/**
 * appendCmd -  adds a new node at the beginning of a cmd_t list.
 *
 * @head: the head of the commande list where add the node
 * @newCmd: the new command to add
 *
 * Return: the address of the new element, or NULL if it failed.
 */
cmd_t *appendCmd(cmd_t **head, cmd_t *newCmd)
{
	if (head != NULL && newCmd != NULL)
	{
		cmd_t *current = *head;

		newCmd->next = NULL;
		if (head == NULL)
		{
			*head = newCmd;
			return (*head);
		}

		while (current && current->next != NULL)
			current = current->next;

		if (current)
		{
			current->next = newCmd;
			return (newCmd);
		}
		return (NULL);
	}
	return (NULL);
}


/**
 * appendCmdArg - add an argument to a command
 *
 * @cmd: the command where add the argument
 * @arg: the argument to add
 *
 * Return: 0 if an error occured and 1 else
 */
int appendCmdArg(cmd_t **cmd, char *arg)
{
	if (cmd && arg)
	{
		if (!(*cmd))
		{
			*cmd = (cmd_t *) malloc(sizeof(cmd_t));
			(*cmd)->args = NULL;
			(*cmd)->op = OP_NONE;
			(*cmd)->argc = 0;
		}

		(*cmd)->args = (char **) realloc((*cmd)->args, (*cmd)->argc + 2);
		if (!(*cmd)->args)
		{
			freeCmd(*cmd);
			return (0);
		}
		(*cmd)->args[(*cmd)->argc + 1] = NULL;
		(*cmd)->args[(*cmd)->argc] = arg;
		(*cmd)->argc++;
		return (1);
	}
	return (0);
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
	{
		free(cmd->args);
		free(cmd);
	}
}


/**
 * freeCmds - free memory allocated for the commands list.
 *
 * @head: The head of the command line list to free.
 */
void freeCmds(cmd_t **head)
{
	if (head)
	{
		cmd_t *current = *head;

		while (current)
		{
			cmd_t *toDelete = current;

			current = current->next;
			freeCmd(toDelete);
		}
	}
	head = NULL;
}

