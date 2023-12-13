#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("simple_shell> ");
}

/**
 * execute_command - Execute a command using fork and exec.
 * @command: The command to execute.
 */
void execute_command(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error forking");
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

/**
 * main - Entry point for the simple shell program.
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_length;

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/* End of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove the newline character at the end of the input */
		command_length = strlen(command);
		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}

		execute_command(command);
	}

	return (0);
}

