#include "main.h"

/**
 * exec - Function that execute a shell command
 * @command: Array of commands arguments
 *
 * Return: 0 on success, or -1 on failure
 */
 extern char **environ;

int execute_command(char **command)
{
	pid_t child_pid;
	int *status = NULL;

	child_pid = fork();

	if (child_pid == -1) /*fork failed*/
	{
		printf("Error: Failed to fork");
		return (-1);
	}

	if (child_pid == 0) /*child process*/
	{
		execve(command[0], command, environ);
		perror("Error: execve failed");
		exit(EXIT_FAILURE);
	}
	else /*parent process*/
	{
		waitpid(child_pid, status, 0);
		if (WIFEXITED(*status))
		{
			free(command);  /* Free memory for command after child process finishes*/
			return WEXITSTATUS(*status);
		}
		else
		{
			perror("Error: Child process did not terminate normally");
			free(command);  /*Free memory for command in case of abnormal termination*/
			return -1;
		}
	}
	return (0);
}
