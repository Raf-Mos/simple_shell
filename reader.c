#include"shell.h"

/**
* reader - read the string
*
* Return: string to split and execute
*/
char *reader(void)
{
	char *str = NULL;
	size_t size_str = 0;
	int n_char = 0;

	if (isatty(STDIN_FILENO) != 0)
	write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&str, &size_str, stdin);
	if (n_char == EOF)
	{
	free(str);
	return (NULL);
	}
	return (str);
}
