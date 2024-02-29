#include "shell.h"
/**
 * _strpbrk - find a set of bytes in accept that match the first argument
 * @s: string to be scanned
 * @accept: struing with chars to match
 * Return: pointer to first char in s that ciontains accept
 */
char *_strpbrk(char *s, char *accept)
{
	int iter;

	while (*s)
	{
		iter = 0;
		while (accept[iter])
		{
			if (*s == accept[iter])
				return (s);
			iter++;
		}
		s++;
	}
	return (NULL);
}
/**
 * _strtok - split a string to tokens
 * @str: string to tokenize
 * @delim: specify the delimiter
 * Return: tokens printed
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *start;

	if (str != NULL)
		token = str;
	else
	{
		if (token == NULL)
			return (NULL);
	}

	start = token;
	token = strpbrk(start, delim);

	if (token != NULL)
	{
		*token = '\0';
		token++;
	}
	return (start);
}
/**
 * _strlen - get the length of a string
 * clone strlen
 * @str: string to find length of
 * Return: length of string
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (0);
}
/**
 * _strcpy - copy a string
 * @src: address o source string
 * @dest: destination address
 * Return: pointer to new address
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatentaes two strings overwriting the terinating null byte
 * and adding it to teh end
 * @dest: string to append to
 * @src: string to append
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int iter = 0, lendest = _strlen(dest);

	while (src[iter] != '\0')
	{
		dest[lendest] = src[iter];
		iter++;
		lendest++;
	}
	dest[lendest + 1] = '\0';
	return (dest);
}
