#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *_strdup(const char *);
int _strlen(char *s);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
void _puts(char *s);
int _putchar(char c);
char *reader(void);
char **splitter(char *);
void p_error(char *file, char *cmd, int index);
char *get_cmd(char *cmd);
char *_getenv(char *name);
void freearrays(char **array);
int executer(char **cmd, char **av, int index);
char *inttoascii(int i);
void reverse_array(char *a, int n);
void exit_sh(char **cmd, char **av, int *status, int counter);
void full_env(char **cmd, int *status);
void handling_builtiner(char **cmd, char **av, int status, int counter);
int _atoi(char *s);
int positive_num(char *s);

#endif
