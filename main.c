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
	char *input, *command_found = NULL, **command = NULL;
	size_t len = 0;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO))
		{
			printf("$$ ");
			fflush(stdout);
		}

		read_input(&input, &len);
		command = parse(input);
		if (command != NULL && command[0] != NULL)
		{
			if ((strcmp(command[0], "exit") == 0) ||
			(strcmp(command[0], "env") == 0))
				built_in(command);

			if (*command[0] != '\0' && access(command[0], X_OK) == 0)
				execute_command(command[0], command);

			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);

				if (command_found != NULL)
					execute_command(command_found, command);
				else
					dprintf(STDERR_FILENO,
				"%d: %s: No such file or directory\n", argc, argv[0]);
				free(command_found);
			}
			free_string_array(command);
		}
	}
	free(input);
	return (0);
}
