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
