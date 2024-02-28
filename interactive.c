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
	char *command = NULL, comment = '#';
	struct stat buf;
	size_t bufsize, i = 0;
	ssize_t check_getline;
	(void) argc;

	while (1)
	{
		_print("#cisfun : $");
		check_getline = getline(&command, &bufsize, stdin);
		if (check_getline == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		strtok(command, "\n");
		if (firstlet(command) == comment)
			continue;
		if (stat(command, &buf) == 0)
			execute(command, argv, envp);
		else
		{
			
			_print(argv[0]);
			_print(": ");
			i++;
			_printd(i);
			_print(": ");
			_print(command);
			_print(": not found\n");
		}
	}
}
/**
 * execute - function to execute given commands
 * @str: comamnd given to execute using execve
 * @argv: argument vactor array
 * @envp: environment variable
 * Return: no return as it'll use execve and fork
 * TRherefore it will overwrote the parent process
 */
void execute(char *str, char **argv, char **envp)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
		execve(str, argv, envp);
	else
	{
		wait(&status);
		return;
	}
}
/**
 * catscom - concantenate comamnds to path and try to exxecute
 * 
void 
