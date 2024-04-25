#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - main function of the simpleShell
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * Return: 0, always succeed
*/
int main(int argc, char *argv[])
{
	char *input, **command = NULL;
	size_t len = 0;
	int status_value = 0;
	int *exit_status = &status_value;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO))
		{
			printf("$$ ");
			fflush(stdout);
		}
		read_input(&input, &len, exit_status);
		command = parse(input, exit_status);
		if (command != NULL && command[0] != NULL)
		{
			if ((strcmp(command[0], "exit") == 0) || (strcmp(command[0], "env") == 0))
			{
				built_in(command, exit_status);
				free_string_array(command);
				continue;
			}
			if (*command[0] != '\0' && access(command[0], X_OK) == 0)
			{
				execute_command(command[0], command, exit_status);
				free_string_array(command);
				continue;
			}
			if (*command[0] != '\0')
				hdle_comm_found(command, argc, argv, exit_status);

			free_string_array(command);
		}
	}
	free(input);
	return (0);
}

/**
 * hdle_comm_found - handles the execution of command found in path
 * from the environ variable
 * @command: Array of commands arguments to execute
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * @exit_status: pointer to an int that tracks exit status
 * Return: 0 on success
 */
int hdle_comm_found(char **command, int argc, char *argv[], int *exit_status)
{
	char *command_found = NULL;

	if (*command[0] != '\0')
	{
		command_found = find_path(command[0], exit_status);

		if (command_found != NULL)
			execute_command(command_found, command, exit_status);
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], argc, command[0]);
			_error("Command not found", exit_status);
		}
		free(command_found);
	}
	return (0);
}
