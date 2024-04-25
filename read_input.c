#include "main.h"

#define BUFFER_SIZE 1024

/**
* read_input - fucntion that displays a prompt for user input,
* and reads it.
* @input: pointer to the input string
* @len: pointer to the BUFFER_SIZE
* @exit_status: pointer to an int that tracks exit status
*Return: dynamically allocated input string
*/
char *read_input(char **input, size_t *len, int *exit_status)
{
	ssize_t read;
	*input = NULL;
	*len = BUFFER_SIZE;

	read = getline(input, len, stdin);
	if (read == -1)
	{
		if (read == EOF)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			_error("EOF", exit_status);
			free(*input);
			exit(*exit_status);
		}
		else
		{
			_error("getLine", exit_status);
			free(*input);
			exit(*exit_status);
		}
	}
	return (*input);
}
