#include "shell.h"
/**
 * interactive_mode - a function to work with the shell's interactive mode
 * @argc: argument count
 * @argv: arguments passed to maain
 * @envp: environment of the program
 * Return: void, it'll exit on error
 */
void interactive_mode(int argc, char **argv, char **envp)
{
	char *command = NULL;
	struct stat buf;
	size_t bufsize;
	ssize_t check_getline;
	(void) argc;
	(void) argv;
	(void) envp;

	while (1)
	{
		_print("$cisfun :");
		check_getline = getline(&command, &bufsize, stdin);
		if (check_getline == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		strtok(command, '\n');
		if (stat(command, &buf) == 0)
			_print("file found");
		else
			_print("Not present");
	}
}
