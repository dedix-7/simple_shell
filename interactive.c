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
	char *command, comment = '#';
	struct stat buf;
	size_t bufsize, i = 0;
	ssize_t check_getline;
	(void) argc;
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
		strtok(command, "\n");
		if (firstlet(command) == comment)
			continue;
		if (stat(command, &buf) == 0)
			execute(command, argv);
		else
		{
			_print(argv[0]);
			_print(" : ");
			i++;
			_printd(i);
			_print(":");
			_print(command);
			_print(" : not found");
		}
	}
}
/**
 * execute - function to execute given commands
 * @str: comamnd given to execute using execve
 * @argv: argument vactor array
 * Return: no return as it'll use execve and fork
 * TRherefore it will overwrote the parent process
 */
void execute(char *str, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
		execve(str, argv, NULL);
	else
	{
		wait(&status);
		return;
	}
}
