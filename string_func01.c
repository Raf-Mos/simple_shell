#include"shell.h"

/**
 * _strlen - returns length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
*/

int _strlen(char *s)
{
	int l = 0;

	while (s[l])
		l++;
	return (l);
}

/**
 * _strcmp - comparaison of two strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: negative if s1 < s2, positive if s1 > s2,
 * zero if s1 == s2
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strdup - duplicate a string
 * @s: the string to duplicate
 *
 * Return: pointer to duplicate string
*/

char *_strdup(const char *s)
{
	int len = 0;
	char *buf;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	for (len++; len--;)
		buf[len] = *--s;
	return (buf);
}

/**
 * _strcat - concatenates two string
 * @dest: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
*/

char *_strcat(char *dest, char *source)
{
	char *buf = dest;

	while (*dest)
		dest++;
	while (*source)
		*dest++ = *source++;
	*dest = *source;
	return (buf);
}
