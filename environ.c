#include "shell.h"

/**
 * _getenv - gets the environment variable of a particular name
 * @name: of the environment variable to searh for
 *
 * Return: pointer to the environment variable
 */

char *_getenv(char *name)
{
	char *token;
	int i;
	char **ep = environ;

	for (i = 0; ep[i] != NULL; i++)
	{
		token = strtok(ep[i], "=");
		while (token)
		{
			if (cmpStr(token, name) == 0)
			{
				return (ep[i] + strLen(name) + 1);
			}
			token = strtok(NULL, "=");
		}
	}
	return (NULL);
}

/**
 * executeFile - execute a given command
 * @command: given path to command
 * Return: status of success or failure, given the macros
 */

int executeFile(char **command)
{
	char *execPath;
	int waitStatus = 0, executeRV = 0;
	pid_t processID = 0;

	execPath = fullpath(command[0]);
	if (execPath == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command[0]);
		return (EXIT_FAILURE);
	}
	processID = fork();

	if (processID == -1)
	{
		perror("Error Creating process");
		exit(EXIT_FAILURE); /* return with exit failure */
	}
	else if (processID == 0)
	{
		executeRV = execve(execPath, command, environ);
		if (executeRV == -1)
		{
			perror("Failed to execute program");
			free(execPath);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		wait(&waitStatus);
	}
	free(execPath);
	return (EXIT_SUCCESS);
}

/**
 * strCopy - copies the content of one string to another
 * @dest: String where it is copying into
 * @src: String being copied
 *
 * Return: New string in dest
 */

char *strCopy(char *dest, char *src)
{
	size_t i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);


	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * strCat - a function to concatenate two strings
 * @dest: mew string being created
 * @src: string being copied to dest
 *
 * Return: a new concatenated string
 */

char *strCat(char *dest, char *src)
{
	int i = 0, dest_length = 0;

	while (dest[i++])
	{
		dest_length++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[dest_length++] = src[i];
	}
	dest[dest_length] = '\0';
	return (dest);
}

/**
 * checkinbuilt - checks if a command is an inbuilt command
 * @string: custom array of strings
 * @inputString: command output
 *
 * Return: 1 if inbuilt or -1 if not inbuilt
 */

int checkinbuilt(char **string, char *inputString)
{
	if (cmpStr(string[0], "exit") == 0)
	{
		free(inputString);
		free(string[0]);
		free(string);
		exit(EXIT_SUCCESS);
	}
	else if (cmpStr(string[0], "env") == 0)
	{
		if (getpid() == 0)
			printenv();
		/* return (1); */
	}
	else
	{
		/* some other logic */
		return (1);
	}
	return (-1);
}
