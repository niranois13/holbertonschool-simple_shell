#include "main.h"

#define BUFFER_SIZE 1024

/**
* read_input - fucntion that displays a prompt for user input,
* and reads it.
*@input: pointer to the input string
*@len: pointer to the BUFFER_SIZE
*Return: dynamically allocated input string
*/
char *read_input(char **input, size_t *len)
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
			free(*input);
			exit(exit_status);
		}
		else
		{
			_perror("getLine\n");
			free(*input);
			exit(exit_status);
		}
	}
	return (*input);
}
