#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 on success || exit status code
 */

int main(void)
{
	char *print = "($)";
	char *input = NULL;
	size_t j, buffsize = 0;
	int i = 0, Rvalue = 0;
	int exit_status = 0;
	char **commandOutput = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, print, strLen(print));
		Rvalue = getline(&input, &buffsize, stdin);

		if (Rvalue == -1)
		{
			free(input);
			exit(exit_status);
		}
		j = 0;
		while (input[j] != '\0' && j < strLen(input) && input[j] == ' ')
		{
			j++;
			continue;
		}
		if (*(input + j) == '\n')
			continue;
		commandOutput = splitInput(input + j);
		if (checkinbuilt(commandOutput, input) == 0)
			exit_status = 0;
		if (executeFile(commandOutput) == EXIT_FAILURE)
			exit_status = 127;
		for (i = 0; commandOutput[i] != NULL; i++)
			free(commandOutput[i]);
		free(commandOutput);
	}
	for (i = 0; commandOutput[i] != NULL; i++)
		free(commandOutput[i]);
	free(commandOutput);
	free(input);
	return (0);
}
