#include"shell.h"

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @source: source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
*/

char *_strncpy(char *dest, char *source, int n)
{
	int i = 0, j;
	char *str = dest;

	while (source[i] != '\0' && i < n - 1)
	{
		dest[i] = source[i];
		i++;
	}
	if (i < n)
	{
	j = i;
	while (j < n)
		{
		dest[j] = '\0';
		j++;
		}
	}
	return (str);
}


/**
 * *_strncat - function that concatenates two strings.
 *              n the number oh characters that will be concatenated
 *
 * @dest: string one
 * @src: string tow
 * @n: input numer of characters
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int j, i = 0;

	while (dest[i] != '\0')
		i++;

	for (j = 0; j < n && src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	return (dest);
}


/**
* _strncmp - comp two string with n char
* @s1: 1st string
* @s2: 2nd string
* @n: number of characters
*
* Return: the comp string
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	s1++;
	s2++;
	n--;
	}
	return (0);
}

/**
 * _strchr - locates a character in a string
 * @s: string to be parsed
 * @c: the char to look for
 *
 * Return: (s) a pointer to memory area s
*/

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
