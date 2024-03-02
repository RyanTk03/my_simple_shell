#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "shell.h"
#include "io.h"
#include "tokenizer.h"
#include "shellData.h"


/**
 * runCmd - run a command
 *
 * @command: a structure which represent the command to run
 *
 * Return: 1 if the command was corretly excecuted and 0 else
 */
char runCmd(shellData_t *shData, cmd_t *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/* Child process */
		execvp(command->args[0], command->args);
		printstr("Error: cannot execute the command ", STDERR_FILENO);
		printline(command->args[0], STDERR_FILENO);
		return (0);
	}
	else if (pid > 0)
	{
		/* Parent process */
		wait(&shData->exitStatus);
		return (1);
	}
	else
	{
		printline("Error: cannot create the child process", STDERR_FILENO);
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
int runCmdList(shellData_t *shData)
{
	cmd_t *current_command = shData->cmdsHead;

	while (current_command != NULL)
	{
		shData->exitStatus = runCmd(shData, current_command);
		current_command = current_command->next;
	}
	return (1);
}


/**
 * getCommandLine - get the command line
 *
 * @shData: the shell data
 *
 * Return: 0 if there a end of file, -1 if there is an error or 1 else
 */
int getCommandLine(shellData_t *shData)
{
	if (shData)
	{
		cmd_t *cmd = NULL;
		char commandLine[BUFFER_SIZE];
		int i = 0, s;

		if (shData->isInteractive)
			printstr("$ ", STDOUT_FILENO);
		s = getline(commandLine, STDIN_FILENO);
		if (s != EOF)
		{
			cmd = tokenize(shData, commandLine, &i, 1);
			while (!cmd)
			{
				appendCmd(&shData->cmdsHead, cmd);
				if (cmd->op == OP_COM)
					break;
				cmd = tokenize(shData, commandLine, &i, 1);
			}
			return (1);
		}
		return (0);
	}
	return (-1);
}


/**
 * startShell - start the shell
 *
 * @argv: argv pass to main function
 * @env: env pass to main function
 *
 * Return: the shell exit value
 */
int startShell(int argc, char **argv, char **env)
{
	shellData_t shData;
	int quit = 1;

	initShellData(&shData, argc, argv, env);
	if (isatty(STDIN_FILENO)) /* check if running interactive mode */
	do
	{
		/* get the command line and tokenize it as a list of cmd_t */
		if (getCommandLine(&shData) == EOF)
			break;

		/* run all the cmd_t tokenized */
		runCmdList(&shData);
		if (shData.quit)
			quit = 1;

		/* reset the shell data for the next command line */
		resetShellData(&shData);
	}
	while (!quit);

	freeShellData(&shData);
	return shData.exitStatus;
}

