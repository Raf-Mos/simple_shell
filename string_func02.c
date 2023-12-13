#include"shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination str
 * @source: the source str
 *
 * Return: pointer to dest
*/

char *_strcpy(char *dest, char *source)
{
	int i = 0;

	if (dest == source || source == 0)
		return (dest);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _puts - puts an input string
 * @s: the string to be printed
 *
 * Return: nothing
*/

void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - write the char to stdout
 * @c: the character to print
 *
 * Return: on success 1, on error -1, and errno is set
 * appropriately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * reverse_array - reverse array of integers
 * @a: array
 * @n: number of elements of array
 *
 * Return: void
 */
void reverse_array(char *a, int n)
{
	int i;
	char j;

	for (i = 0; i < n--; i++)
	{
		j = a[i];
		a[i] = a[n];
		a[n] = j;
	}
}
