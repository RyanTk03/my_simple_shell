#include "shell.h"


/**
 * runCmd - run a command
 *
 * @command: a structure which represent the command to run
 *
 * Return: 1 if the command was corretly excecuted and 0 else
 */
char runCmd(cmd_t *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/* Child process */
		execvp(command->args[0], command->args);
		perror("Erreur lors de l'exécution de la commande");
		return (0);
	}
	else if (pid > 0)
	{
		/* Parent process */
		wait(NULL);
		return (1);
	}
	else
	{
		perror("Erreur lors de la création du processus enfant");
		return (0);
	}
}


/**
 * runCmdList - run a list of command
 *
 * @cmdsHead: the list of command to execute
 *
 * Return: 1 if all command were executed corretly and 0 else
 */
char runCmdList(cmd_t *cmdsHead)
{
	cmd_t *current_command = cmdsHead->first;

	while (current_command != NULL)
	{
		runCmd(current_command);
		current_command = current_command->next;
	}
}
