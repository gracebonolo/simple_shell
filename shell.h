#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

void display_prompt(void);
void execute_command(const char *command);
int is_positive_number(const char *str);
char *_getenv(const char *name);
int _setenv(char **args);
int _unsetenv(char **args);

#endif

