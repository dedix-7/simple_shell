#include "shell.h"
/**
 * interactive_mode - functin to work in the shell'd interactive mode
 * @argc: arguent count
 * @argv: vector array
 * @envp: eviornment variable
 * Return: nothing, void
 * on error, it'll exit
 */
void interactive_mode(int argc, char **argv, char **envp)
{
	char **line;
	size_t n;

	while (1)
	{
		_print("myshell$ ");
		getline(line, &n, stdin);
		
