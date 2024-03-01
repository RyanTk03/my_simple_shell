#include "shellData.h"


/**
 * initShellData - init the shell data
 *
 * @data: the shell data structure
 * @argv: the shell arguments values
 * @env: the shell environment variable values
 */
void initShellData(shellData_t *data, char **argv, char **env)
{
	if (data)
	{
		data->cmdsHead = NULL;
		data->alias = NULL;
		fillEnvDict(data->dict, env);
		data->argv = argv;
	}
}


/**
 * resetShellData - reset the temporal data of the shell
 *
 * @shData: a pointer to the shell data
 */
void resetShellData(shellData_t *shData)
{
	freeCmds(shData->cmdsHead);
}


/**
 * freeShellData - free the shell data (like pointer)
 *
 * @shData: a pointer to the shell data to free
 */
void freeShellData(shellData_t *shData)
{
	freeCmds(shData->cmdsHead);
	freeDict(shData->alias);
	freeDict(shData->env);
	freeList(shData->PATH);
}


/**
 * replaceAlias - find the alias corresponding to a string
 *
 * @shData: shell data
 * @src: the source
 *
 * Return: 1 if an alias where find and replaced or 0 else
 */
int *replaceAlias(shellData_t *shData, char **src)
{
	if (shData && src)
	{
		dictItem_t *alias = getDictValue(shData->alias, *src, NULL);

		if (alias)
		{
			if (mystrset(alias->value, src))
				return (1);
			return (0);
		}
	}
	return (0);
}
