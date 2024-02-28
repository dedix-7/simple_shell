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
	char *var, **cpyenv, *value;
	char *ret;

	if (name == NULL)
		return (NULL);
	cpyenv = copyenviron(envp);
	if (!cpyenv)
		cpyenv = envp;
	for (cpyenv != NULL; cpyenv[i]; i++)
	{
		var = strtok(cpyenv[i], "=");
		value = strtok(NULL, "");
		if (var && (_strcmp(var, name) == 0))
		{
			ret = _strdup(value);
			if (!ret)
				return (var);
			free_copyenviron(cpyenv);
			return (ret);
		}
	}
	free_copyenviron(cpyenv);
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
		copy[i] = _strdup(envp[i]);
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

	if (copy == NULL)
		return (0);
	if (*copy == NULL)
		return (0);
	while (copy[size])
		size++;
<<<<<<< HEAD
	printf("Size is %d blocks", size);
	for (i = 0; i < (size - 3) ; i++)
	{
		if (copy[i] == NULL)
			continue;
		printf("attempting to free %d block", i);
=======
	for (i = 0; i < size ; i++)
>>>>>>> 14570a19a7c28498b17e2ba15b39c8ca252195d6
		free(copy[i]);
	free(copy);
	return (1);
}
/**
 * main - test functions
 * @argc: argument count
 * @argv: argument vector
 * @envp: envviornment varibale
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **envp)
{
	char *en, *tes;

<<<<<<< HEAD
	copy = copyenviron(envp);
	printf("block 57 is %s ", envp[57]);
	for (i = 0; envp[i]; i++)
		printf("%s\n%s\n", envp[i], copy[i]);
	return (free_copyenviron(copy));
=======
	en = _getenv("SHELL", envp);
	tes = getenv("SHELL");
/*	printf("\nThe functions yields value of PATH as \n%s\n and stdlib gives\n%s\n", en, tes);*/
	return (0);
>>>>>>> 14570a19a7c28498b17e2ba15b39c8ca252195d6
}
