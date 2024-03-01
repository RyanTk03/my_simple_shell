#include <unistd.h>
#include "env.h"
#include "mystring.h"


/**
 * fillEnvDict - fill a dict with environment variable
 *
 * @dict: the dict to fill
 * @env: the env variables
 */
void fillEnvDict(dict_t *dict, char **env)
{
	int i = 0;

	while (env[i] != NULL && i < MAX_ENV_VARS)
	{
		char *env_var = env[i];
		char *delimiter = mystrchr(env_var, '=');

		if (delimiter != NULL)
		{
			int key_len = delimiter - env_var;
			int value_len = strlen(delimiter + 1);
			char *key = (char *)malloc(key_len + 1);
			char *value = (char *)malloc(value_len + 1);

			mystrncpy(env_var, key, 0, key_len);
			key[key_len] = '\0';

			mystrncpy(delimiter + 1, value, 0, value_len);
			value[value_len] = '\0';

			setDictValue(dict, key, value);

			free(key);
			free(value);
		}
		i++;
	}
}

