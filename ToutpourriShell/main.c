#include "header.h"

#define BUFFER_SIZE 1024

/**
 * main - main function of the simpleShell
 * @argc: number of command-line arguments.
 * @argv: array of command-line arguments.
 * Return: 0, always succeed
*/
int main(int argc, char **argv)
{
	char *input = NULL, *command_found = NULL;
	size_t len = 0;
	char **command;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		_getline(&input, &len);
		command = parse(input);

		if (command != NULL && command[0] != NULL)
		{
			if ((strcmp(command[0], "exit") == 0) ||
			(strcmp(command[0], "env") == 0))
			built_in(command);

			if (access(command[0], X_OK) == 0)
			{
				execute_command(command[0], command);
			}
			else if (command_found != NULL)
			{
				command_found = find_path(command[0]);
				execute_command(command_found, command);
			}
			else
			{
				dprintf(STDERR_FILENO,
				"%s: %d: No such file or directory\n", argv[0], argc);
			}
		}
		free_string_array(command);
		free(command_found);
	}
	return (0);
}

/**
* _getline - function that handles a call to getline and it's potentia errors
* @input: adress of the user input to allocate memory for
* @len: address of the length of the user input.
* Return: pointer to the input string, else on error
*/
char *_getline(char **input, size_t *len)
{
	ssize_t read;
	*input = NULL;
	*len = BUFFER_SIZE;

	read = getline(input, len, stdin);
	if (read == -1)
	{
		if (read == EOF)
		{
			printf("\n");
			free(*input);
			exit(errno);
		}
		else
		{
			perror("getLine\n");
			free(*input);
			exit(errno);
		}
	}
	return (*input);
}
