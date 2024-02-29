#include "shell.h"

/**
 * _strdup - duplicates a string into newly allocated array
 *
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */

char *_strdup(char *str)
{
	int i, j, len = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		ptr[j] = str[j];
	ptr[len] = '\0';

	return (ptr);
}

/**
 * strLen - returns the length of a string
 * @input: string input
 *
 * Return: length of the string
 */

size_t strLen(const char *input)
{
	int idx = 0;
	int n = 0;

	for (idx = 0; input[idx] != '\0'; idx++)
		n++;

	return (n);
}

/**
 * cmpStr - a function to check if two strings are the same
 * @s01: input one
 * @s02: input string two
 *
 * Return: 0 if the strings are the same || 1 if they are not
 */

int cmpStr(char *s01, char *s02)
{
	while (*s01 && (*s01 == *s02))
	{
		s01++;
		s02++;
	}
	if (*s01 == *s02)
		return (0);
	else if (*s01 < *s02)
		return (-1);
	else
		return (1);
}

/**
 * splitInput - Splits an input string into array of strings
 * @string: input string
 *
 * Return: array of Strings
 */

char **splitInput(char *string)
{
	char **customArray;
	char *splitToken = NULL;
	size_t count = 10; /* number or input strings*/
	char *delim = " \n";
	int idx = 0;

	customArray = malloc(sizeof(char *) * count + 1);

	if (customArray == NULL)
	{
		perror("Error creating customArray");
		exit(EXIT_FAILURE); /* change to EXIT_FAILURE */
	}
	splitToken = strtok(string, delim);
	while (splitToken != NULL)
	{
		customArray[idx] = _strdup(splitToken);
		idx++;
		splitToken = strtok(NULL, delim);
	}
	customArray[idx] = NULL; /* NULL terminate at the end */

	return (customArray);
}
/**
 * _getline - reads input from a stream
 * @lineptr: a buffer array to read input into
 * @n: size of input to read
 * @fd: file descriptor
 *
 * Return: number of bytes Read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	/* int idx = 0; */
	/* char buffer[1024]; */
	ssize_t readBytes = 0;

	readBytes = read(fd, (lineptr), sizeof(lineptr));
	 /* ssize_t read(int fd, void *buf, size_t count); */

	printf("readBytes is %ld\n", readBytes);
	if (readBytes == -1)
	{
		perror("Error Reading from stream:");
		/*free(buffer);*/
		return (-1);
	}
	(lineptr)[readBytes] = '\0';
	write(STDOUT_FILENO, (lineptr), readBytes);

	*n = readBytes;

	return (readBytes);
}
