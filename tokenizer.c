#include "tokenizer.h"

/**
 * getOperator - get the operator in the current position of the tokenization
 *
 * @str: the sring to check
 * @current: the current position of the tokenization processus
 *
 * Return: the current operator or OP_NONE if there is no operator in the
 * current position
 */
char getOperator(char *str, int *current)
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
			*current++;
			return (OP_OR);
		}
		else
			return (OP_PIPE);
	}
	else if (str[*current] == '&')
	{
		if (str[*current + 1] == '&')
		{
			*curent++;
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
		*i++;
	}
}


/**
 * getNextTokenLen - get next token len
 *
 * @str: the source string
 * @i: the current source tokenization index
 *
 * Return: the length of the next token
 */
int getNextTokenLen(char *str, int i)
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
 * tokenize - tokenize a source string
 * this function tokenize a string by doing a return for each token found in
 * the source. To get all token of a source, the same memorie address should
 * be send in param until a NULL token is returned
 *
 * @src: the source
 *
 * Return: a command that correspond to a token or NULL if there is a probleme
 * or if there no more token found
 */
cmd_t *tokenize(char *src)
{
	static int i;

	if (src != NULL && src[i] != '\0')
	{
		cmd_t *cmd = NULL;

		initCmd(&cmd);
		if (cmd != NULL)
		{
			static char *srcSaved;
			int j = 1;
			char stop = 0;

			if (src != srcSaved)
				i = 0;
			gotoNextNotSpace(src, &i);
			while (!stop)
			{
				int len = getNextTokenLen(src, i);
				char token = malloc(sizeof(char) * (i + 1));

				if (!token)
				{
					freeCmd(cmd);
					return (NULL);
				}
				cmd->args = (cmd_t **) realloc(cmd->args, j + 1);
				if (!cmd->args)
				{
					freeCmd(cmd);
					free(token);
					return (NULL);
				}
				cmd->args[j] = NULL;
				cmd->args[j - 1] = token;
				mystrcopy(src, token, i, len);
				i += len;
				gotoNextNotSpace(src, &i);
				token->op = get_Operator(src, &i);
				if (token->op != OP_NONE)
					stop = 1;
				j++;
				i++;
			}
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

