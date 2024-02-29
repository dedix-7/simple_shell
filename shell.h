#ifndef SHELL_H
#define SHELL_H

#define ACTIVE 1

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* int EXIT_STATUS = 0; */
extern char **environ;

char *_getenv(char *name);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **splitInput(char *string);
int checkinbuilt(char **string, char *inputString);
char *fullpath(char *command_Idx);
int executeFile(char **command);
void printenv(void);
char *_strpbrk(char *s, char *accept);
char *_strtok(char *str, const char *delim);
int cmpStr(char *s01, char *s02);
size_t _strlen(char *str);
size_t strLen(const char *input);
char *strCopy(char *dest, char *src);
/* char *_strcat(char *dest, char *src); */
char *strCat(char *dest, char *src);
char *_strdup(char *str);
int _puts(char *str);
int _putchar(char c);
int _fputchar(int fildes, char c);
int _fprint(int fildes, char *str);
int _print(char *str);
int _printd(int d);
int _fprintd(int fildes, int d);

#endif /* SHELL_H */
