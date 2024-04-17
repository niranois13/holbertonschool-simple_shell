#include "main.h"

/**
 * exec - Function that execute a shell command
 * @command: Array of commands arguments
 *
 * Return: 0 on success, or -1 on failure
 */
 extern char **environ;

int execute_command(char **command )
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		printf("Error: Failed to fork");
		return (-1);
	}

	execve(command[0], command, environ);

	if (child_pid > 0)
	{
		wait(NULL);
	}

	free(command);
	return (0);
}
