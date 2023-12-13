#include"shell.h"

/**
 * positive_num - check if s is a positive number
 * @s: the number to check
 *
 * Return: 1 on success, 0 on failure
*/
int positive_num(char *s)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
*/

int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
	if (*s == '-')
		sign *= -1;
	else if (*s >= '0' && *s <= '9')
		num = (num * 10) + (*s - '0');
	else if (num > 0)
		break;
	} while (*s++);

	return (num * sign);
}
