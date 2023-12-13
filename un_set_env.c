#include "shell.h"

/**
* _unsetenv - delete an environ line
* @cmd: command
* Return: 0 (Success)
*/

int _unsetenv(char **cmd)
{
	int i = 0, j;

	if (!cmd[1])
	{
		freearrays(cmd);
		return (-1);
	}
	while (environ[i])
	{
		if (_strncmp(environ[i], cmd[1], _strlen(cmd[1])) == 0)
		{
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			freearrays(cmd);
			return (0);
		}
		i++;
	}
	freearrays(cmd);
	return (-1);
}

/**
* _setenv - Initialize a new environment variable,
*				or modify an existing one
* @cmd: command
* Return: 0 (Success)
*/

int _setenv(char **cmd)
{
	int i;
	char *new_env;

	if (cmd[1] == NULL || cmd[2] == NULL || _strchr(cmd[1], '=') != NULL)
	{
		freearrays(cmd);
		return (-1);
	}
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], cmd[1], _strlen(cmd[1])) == 0 &&
				environ[i][_strlen(cmd[1])] == '=')
		{
			new_env = malloc(_strlen(cmd[1]) + _strlen(cmd[2]) + 2);
			if (new_env)
			{
				_strcpy(new_env, cmd[1]);
				_strcat(new_env, "=");
				environ[i] = _strcat(new_env, cmd[2]);
				free(new_env), new_env = NULL;
				freearrays(cmd);
				return (0);
			}
			freearrays(cmd);
			return (-1);
		}
	}
		new_env = malloc(_strlen(cmd[1]) + _strlen(cmd[2]) + 2);
		_strcpy(new_env, cmd[1]);
		_strcat(new_env, "=");
		environ[i] = _strcat(new_env, cmd[2]);
		environ[i + 1] = NULL;
		free(new_env), new_env = NULL;
		freearrays(cmd);
		return (0);
}
