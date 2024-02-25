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
