#include "shell.h"
/**
 * main - begin execution of the shell
 * @argc: rgument count
 * @argv: argument vectors
 * @envp: environment variable
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	if (isatty(STDIN_FILENO) == 1)
		interactive_mode(argc, argv, envp);
	else
		non_interactive_mode(argc, argv, envp);
	return (0);
}
