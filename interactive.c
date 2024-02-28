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
	char *command = NULL, *cmd;
	struct stat buf;
	size_t bufsize;
	ssize_t check_getline;
	(void) argc;
	(void) argv;
	(void) envp;
	pid_t child;

	while (1)
	{
		_print("$cisfun :");
		check_getline = getline(&command, &bufsize, stdin);
		if (check_getline == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		strtok(command, 10);
		
	}
}
