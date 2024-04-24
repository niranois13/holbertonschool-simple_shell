#include "header.h"

/**
* execute_command - execute commands entered by user and found in PATH
* @path: path to the directory matching the command input
* @command: the command input
* Retun: 0 on success
*/
int execute_command(char *path, char **command)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		fprintf(stderr, "fork failed: %s\n", strerror(errno));
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			perror("execve");
			exit(errno);
		}
		else
		{
			free(path);
			free_string_array(command);
		}
	}
	else
	{
		int status;
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}

		if (!WIFEXITED(status))
		{
			fprintf(stderr, "Child process did not exit normally\n");
			free_string_array(command);
			free(path);
			return (-1);
		}
	}
	free_string_array(command);
	free(path);
	return (0);
}
