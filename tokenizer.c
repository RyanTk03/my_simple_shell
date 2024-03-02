#include "tokenizer.h"
#include "mystring.h"

/**
 * getCurrentCharType - get the type of the current charactere(the type of
 * operator if it is one or OP_NONE if it is not an operator
 *
 * @str: the sring to check
 * @current: the current position of the tokenization processus
 *
 * Return: the current operator or OP_NONE if there is no operator in the
 * current position
 */
char getCurrentCharType(char *str, int *current)
{
	if (str[*current] == ';')
	{
		return (OP_SEP);
	}
	else if (str[*current] == '#')
	{
		return (OP_COM);
	}
	else if (str[*current] == '|')
	{
		if (str[*current + 1] == '|')
		{
			(*current)++;
			return (OP_OR);
		}
		else
			return (OP_PIPE);
	}
	else if (str[*current] == '&')
	{
		if (str[*current + 1] == '&')
		{
			(*current)++;
			return (OP_AND);
		}
		else
			return (OP_AMPERSAND);
	}


	return (OP_NONE);
}


/**
 * gotoNextNotSpace - go to next charactere that is not a space
 *
 * @str: the string to go through
 * @i: the index of the current charactere
 */
void gotoNextNotSpace(char *str, int *i)
{
	while (str[*i] == ' ')
	{
		(*i)++;
	}
}


/**
 * getNextArgLen - get next token len
 *
 * @str: the source string
 * @i: the current source tokenization index
 *
 * Return: the length of the next token
 */
int getNextArgLen(char *str, int i)
{
	int len = 0;

	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}

	return (len);
}


/**
 * getNextArgStr - get the string coresponding to an argument value for a cmd
 *
 * @src: the source from where get the token
 * @from: the begining index from where get the token
 * @len: the length of the token
 *
 * Return: the token created
 */
char *getNextArgStr(char *src, int from, int len)
{
	char *arg = (char *) malloc(sizeof(char) * (len + 1));

	if (!arg)
		return (NULL);

	if (mystrncpy(src, arg, from, len) < len)
	{
		free(arg);
		return (NULL);
	}
	arg[len] = '\0';
	return (arg);
}


/**
 * tokenize - tokenize a source string
 * this function tokenize a string by doing a return for each token found in
 * the source. To get all token of a source, the same memorie address should
 * be send in param until a NULL token is returned
 *
 * @shData: the shell data
 * @src: the source
 * @from: the current index of the source tokenization
 * @handleAlias: if the tokenization should take care of alias
 *
 * Return: a command that correspond to a token or NULL if there is a probleme
 * or if there no more token found
 */
cmd_t *tokenize(shellData_t *shData, char *src, int *from, int handleAlias)
{
	if (src != NULL && src[*from] != '\0')
	{
		cmd_t *head = NULL, *currentCmd = NULL;
		int argc = 1;
		char stop = 0;

		while (!stop)
		{
			gotoNextNotSpace(src, from);
			{
			int len = getNextArgLen(src, *from);
			char *argStr = getNextArgStr(src, *from, len);

			if (argc == 1 && handleAlias && replaceAlias(shData, &argStr))
			{
				int i = 0;
				cmd_t *cmdi = tokenize(shData, argStr, &i, 0);

				while (!cmdi)
				{
					appendCmd(&head, cmdi);
					currentCmd = cmdi;
					cmdi = tokenize(shData, argStr, &i, 0);
				}
			}
			else
				appendCmdArg(&currentCmd, argStr);
			*from += len;
			gotoNextNotSpace(src, from);
			currentCmd->op = getCurrentCharType(src, from);
			if (currentCmd->op != OP_NONE)
				stop = 1;
			argc++;
			free(argStr);
			}
		}
		return (head);
	}
	return (NULL);
}
