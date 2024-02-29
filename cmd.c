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
	if (head && newCmd)
	{
		newCmd->next = NULL;
		if (!*head)
		{
			*head = newCmd;
			return (*head);
		}
		cmd_t *current = *head;

		while (current->next)
			current = current->next;

		current->next = newCmd;

		return (newCmd);
	}
	return (NULL);
}


/**
 * appendCmdArg - add an argument to a command
 *
 * @cmd: the command where add the argument
 * @arg: the argument to add
 * @argc: the current length of the command arguments
 *
 * Return: -1 if an error occured and 1 else
 */
int appendCmdArg(cmd_t *cmd, char *arg, int argc)
{
	if (cmd && arg)
	{
		cmd->args = (char **) realloc(cmd->args, argc + 1);
		if (!cmd->args)
		{
			freeCmd(cmd);
			free(token);
			return (-1);
		}
		cmd->args[argc] = NULL;
		cmd->args[argc - 1] = arg;
		return (1);
	}
	return (-1);
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
}

