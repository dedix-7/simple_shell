#include "shell.h"
/**
 * _putchar - clones putchar
 * @c: char
 * Return: 1 on success, non-1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _fputchar - puchar to a gucen file descriprir
 * @fildes: file descriptor
 * @c: charcters to rint
 * Return: 1 on success, non-1 on error
 */
int _fputchar(int fildes, char c)
{
	return (write(fildes, &c, 1));
}
/**
 * _fprint - clones fprintf
 * @fildes: file descriptor
 * @str: string to rint to file
 * Return: number of chars prited
 */
int _fprint(int fildes, char *str)
{
	int i = 0;

	while (str[i])
		i += _fputchar(fildes, str[i]);
	return (i);
}
/**
 * _print - clone puts
 * @str: string to print
 * Return: number of chars printed
 */
int _print(char *str)
{
	int i = 0;

	while (str[i])
		i += _putchar(str[i]);
	return (i);
}
/**
 * _printd - print an int
 * @d: integer to print
 * Return: number of digits
 */
int _printd(int d)
{
	int rem, quotient;

	if (d < 0)
	{
		_putchar('-');
		d = -d;
	}
	rem = d % 10;
	quotient = d / 10;
	if (quotient > 0)
		_printd(quotient);
	return (_putchar(rem + '0'));
}
