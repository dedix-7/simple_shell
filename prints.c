#include "shell.h"
/**
 * _putchar - write a char to stdout
 * @c: char to write
 * Return: 1 on success, non-negative oe on failure
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _puts - print a string
 * @str: string to print
 * Return: chars printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
	i++;
	return (i);
}
/**
 * printenv - print the environment variables
 * no aruments
 * Return: nothing
 */

void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
	}
}

/**
 * fullpath - finds the fullpath to a command
 * @command_Idx: input command
 *
 * Return: Fullpath to a command
 */

char *fullpath(char *command_Idx)
{
	char *fullPath, *dupFilePath, *token;
	size_t len = 0;
	struct stat statbuf;
	char *filePath = getenv("PATH");

	if (command_Idx == NULL)
	{
		perror("NULL input received");
		return (NULL);
	}
	if (stat(command_Idx, &statbuf) == 0)
	{
		return (_strdup(command_Idx));
	}
	dupFilePath = _strdup(filePath);
	token = strtok(dupFilePath, ":");
	while (token != NULL)
	{
		len = strlen(command_Idx) + strlen(filePath) + 2;
		fullPath = malloc(len);
		if (fullPath == NULL)
			break;
		else if (fullPath != NULL)
		{
			strCopy(fullPath, token);
			strCat(fullPath, "/");
			strCat(fullPath, command_Idx);
			if (stat(fullPath, &statbuf) == 0)
			{
				free(dupFilePath);
				return (fullPath);
				printf("Full :%s\n", fullPath);
			}
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	free(dupFilePath);
	return (NULL);
}
