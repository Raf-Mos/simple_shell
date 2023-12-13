#include"shell.h"

/**
 * executer - execute the commands
 * @cmd: cmd to execute
 * @av: argument vector
 * @index: indexing commands
 *
 * Return: executed command, or status
*/
int executer(char **cmd, char **av, int index)
{
	pid_t child_pid;
	int status;
	char *full_path;

	full_path = get_cmd(cmd[0]);
	if (full_path == NULL)
	{
	p_error(av[0], cmd[0], index);
	freearrays(cmd);
	return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
	if (execve(full_path, cmd, environ) == -1)
	{
		free(full_path), full_path = NULL;
		freearrays(cmd);
	}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	freearrays(cmd);
	free(full_path), full_path = NULL;
	}
	return (WEXITSTATUS(status));
}
