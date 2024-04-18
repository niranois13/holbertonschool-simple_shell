#include "main.h"

/**
 * execute_command - Function that execute a shell command
 * @command: Array of commands arguments
 * @path: pointer to the constant path
 *
 * Return: 0 on success, or -1 on failure
 */

int execute_command(const char *path, char **command)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		printf("Error: Failed to fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		execve(path, command, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
