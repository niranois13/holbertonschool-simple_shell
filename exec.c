#include "main.h"

/**
 * execute_command - Function that execute shell commands
 * from the environ variable
 * @command: Array of commands arguments to execute
 * @path: pointer to the string containing the path of the command to execute
 * Return: 0 on success, or -1 on failure
 */

int execute_command(const char *path, char **command)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		_perror("fork");
		fprintf(stderr, "%s\n", strerror(errno));
		return (-1);
	}

	if (child_pid == 0)
	{
		execve(path, command, environ);
		_perror("execve");
		exit(exit_status);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
