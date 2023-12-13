#include"shell.h"

/**
* freearrays - free a 2D array
* @array: array to free
* Return: void
*/

void freearrays(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}
