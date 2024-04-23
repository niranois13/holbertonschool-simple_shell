#include "main.h"
#define BUFFER_SIZE 1024

/**
* prompt_and_read_input_2 - fucntion that displays a prompt for user input,
* and reads it.
*@input: pointer to the input string
*@len: pointer to the BUFFER_SIZE
*Return: dynamically allocated input string
*/
char *prompt_and_read_input_2(char **input, size_t *len)
{
	ssize_t read;
	*input = NULL;
	*len = BUFFER_SIZE;

	read = getline(input, len, stdin);
	if (read == -1)
	{
		if (read == EOF)
		{
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
