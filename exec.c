#include "main.h"

/**
* execute_command - Function that execute shell commands
*						from the environ variable
* @path: Pointer to the string containing the path of the command to execute
* @command: Array of commands arguments to execute
* @exit_status: Pointer to the exit status variable to update
* Return: 0 on success, or -1 on failure
*/
int execute_command(const char *path, char **command, int *exit_status)
{
	pid_t child_pid;
	int status, child_exit_status;

	child_pid = fork();

	if (child_pid == -1)
	{
		_perror("fork", exit_status);
		return (-1);
	}

	if (child_pid == 0)
	{
		execve(path, command, environ);
		_perror("execve", exit_status);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status))
		{
			child_exit_status = WEXITSTATUS(status);
			if (child_exit_status != 0)
				*exit_status = child_exit_status;
		}
		else
			*exit_status = 1;
	}
	return (0);
}
