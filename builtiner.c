#include"shell.h"

/**
* full_env - print environ
* @cmd: command
* @status: status
* Return: void
*/

void full_env(char **cmd, int *status)
{
	int i = 0;

	while (environ[i] != NULL)
	{
	write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
	write(STDOUT_FILENO, "\n", 1);
	i++;
	}
	freearrays(cmd);
	*status = 0;
}

/**
* exit_sh - exit shell and print exit error msg
* @cmd: command
* @av: args
* @status: status
* @counter: line number
* Return: void
*/

void exit_sh(char **cmd, char **av, int *status, int counter)
{
	int exit_val = (*status);
	char *ind, error_msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (positive_num(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
		}
		else
		{
			ind = inttoascii(counter);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, ind, _strlen(ind));
			write(STDERR_FILENO, error_msg, _strlen(error_msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(ind);
			freearrays(cmd);
			return;
		}
	}
	freearrays(cmd);
	exit(exit_val);
}
