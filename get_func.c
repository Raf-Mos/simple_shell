#include"shell.h"

/**
* _getenv - function that returns the key's value
*			from the environ
* @name: key's name
* Return: key's value
*/
char *_getenv(char *name)
{
	int i;
	char *var, *temp, *temp2, *value;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		var = strtok(temp, "=");
		if (_strcmp(var, name) == 0)
		{
			value = strtok(NULL, "\n");
			temp2 = _strdup(value);
			free(temp);
			return (temp2);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}

/**
* get_cmd - returns the full path of a command
* @cmd: command key
* Return: command's path
*/
char *get_cmd(char *cmd)
{
	char *token, *full_cmd, *path;

	if (access(cmd, F_OK) == 0)
	{
		return (_strdup(cmd));
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	token = strtok(path, ":");
	while (token)
	{
		full_cmd = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, token);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (access(full_cmd, F_OK) == 0)
			{
				free(path);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			token = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}

/**
* p_error - print error msg
* @file: file name
* @cmd: command
* @index: line number
* Return: void
*/

void p_error(char *file, char *cmd, int index)
{
	char *ind, error_msg[] = ": not found\n";

	ind = inttoascii(index);

	write(STDERR_FILENO, file, _strlen(file));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, _strlen(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, error_msg, _strlen(error_msg));

	free(ind);
}

/**
* inttoascii - change integer into ascii value
* @i: integer
* Return: ascii value
*/
char *inttoascii(int i)
{
	char array[25];
	int j = 0;

	if (i == 0)
		array[j++] = '0';
	else
	{
		while (i > 0)
		{
			array[j++] = (i % 10) + '0';
			i /= 10;
		}
	}
	array[j] = '\0';
	reverse_array(array, j);

	return (_strdup(array));
}
