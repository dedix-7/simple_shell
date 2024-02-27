#include "shell.h"
/**
 * _getenv - get the environment variable
 * @name: command to look for
 * @envp: environemnt variable
 * Return: pointer to command string or NULL on failure
 */
char *_getenv(char *name, char **envp)
{
	int i = 0;
	char *var;

	if ((name == NULL))
	while (envp[i])
	{
		var = strtok(envp[i], "=");
		if (strcmp(var, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
/**
 * copyenviron - a function to copy the environment variables
 * @envp: environemnt variable
 * Return: copied variable
 */
char **copyenviron(char **envp)
{
	char **copy;
	int i = 0, size = 0;

	while (envp[size] != NULL)
		size++;
	copy = malloc((size + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		if (!envp[i])
			break;
		copy[i] = strdup(envp[i]);
		if (strcmp(envp[i], copy[i]) != 0)
		{
			printf("the variable %d did not copy well");
			exit(EXIT_SUCCESS);
		}
	}
	copy[size] = '\0';
	return (copy);
}
/**
 * free_copyenviron - frees a copy of the environ variable
 * @copy: copy of the environment variable
 * Is a double pointer
 * Return: 1 on success, zero otherwise
 */
int free_copyenviron(char **copy)
{
	int i = 0, size = 0;
	char *str;

	if (copy == NULL)
		return (0);
	if (*copy == NULL)
		return (0);
	while (copy[size])
		size++;
	printf("Size is %d blocks", size);
	for (i = 0; i < size ; i++)
		free(copy[i]);
	free(copy);
	return (1);
}
