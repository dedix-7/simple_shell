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
	int i = 0, size;

	size = sizeof(envp)/sizeof(envp[0]);
	copy = malloc(size * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	for (i = 0; envp[i]; i++)
		copy[i] = strdup(envp[i]);
	return (copy);
}
/**
 * free_copyenviron - frees a ciopy of the environ variable
 * @copy: copy of the environment variable
 * Is a doiuble pointer
 * Return: 1 on success, zero otherwise
 */
int free_copyenviron(char **copy)
{
	int i = 0;

	for (i = 0; copy[i]; i++)
		free(copy[i]);
	free(copy);
	return (1);
}
/**
 * main - test copy environ
 * variosu args
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char **copy;
	int i;

	copy = copyenviron(envp);
	for (i = 0; envp[i]; i++)
		printf("%s            %s", envp[i], copy[i]);
	return (free_copyenviron(copy));
}