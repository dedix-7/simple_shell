#include "shell.h"
/**
 * _strlen - get the length of a string
 * @str: string to find length
 * Return: length of string
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcpy - copy a string to a given address
 * @src: source to copy from
 * @dest: destination
 * Return: destiation address, or NULL on failure
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
 * _strdup - duplicates a string into newly allocated array
 *
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int size = 0;
	char *ptr, *ret;

	if (!str)
		return (NULL);

	ptr = str;
	while (*ptr++)
		size++;

	ret = malloc(size + 1);
	if (!ret)
		return (NULL);

	ptr = ret;
	while (*str)
		*ptr++ = *str++;

	*ptr = 0;
	return (ret);
}
