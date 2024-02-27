#ifndef SHELL_H
#define SHELL_H

#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int _putchar(char c);
int _fputchar(int fildes, char str);
int _fprint(int fildes, char *str);
int _print(char *str);
int _strlen(char *str);
char *_strcpy(char*src, char *dest);
char *_strdup(char *str);
void interactive_mode(int argc, char **argv, char **envp);
void non_interactive_mode(int argc, char **argv, char **envp);
char *_getenv(char *cmd, char **envp);

#endif /* SHELL_H */
