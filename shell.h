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
#include<sys/stat.h>
#include<signal.h>

int _putchar(char c);
int _fputchar(int fildes, char str);
int _fprint(int fildes, char *str);
int _print(char *str);
int _strlen(char *str);
char *_strcpy(char *src, char *dest);
char *_strdup(char *str);
void interactive_mode(int argc, char **argv, char **envp);
void non_interactive_mode(int argc, char **argv, char **envp);
char *_getenv(char *cmd, char **envp);
char **copyenviron(char **envp);
int free_copyenviron(char **copy);
int _strcmp(char *s1, char *s2);
int _printd(int d);
int execute(char *str, char **av, char **ev);
char firstlet(char *str);
char *str_concat(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *catscom(char *com, char **av, char **ev);

#endif /* SHELL_H */
