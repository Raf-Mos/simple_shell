#include"shell.h"

/**
* main - simple shell main function
* @ac: input
* @av: input arg
* Return: status
*/
int main(int ac, char **av)
{
	char *buf = NULL, **cmd = NULL;
	int status = 0, counter = 0;
	(void)ac;

	while (1)
	{
		buf = reader();
		if (buf == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
		return (status);
		}
		counter++;
		cmd = splitter(buf);
		if (cmd == NULL)
			continue;

		if (_strcmp(cmd[0], "exit") == 0)
			exit_sh(cmd, av, &status, counter);
		else if (_strcmp(cmd[0], "env") == 0)
			full_env(cmd, &status);
		else
			status = executer(cmd, av, counter);
	}
}
