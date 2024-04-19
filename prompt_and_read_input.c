#include "main.h"
#define BUFFER_SIZE 1024
/**
 * 
 * 
*/

void sigint_handler()
{
    printf("\nTop-Shell:€ ");
    fflush(stdout);
}

/**
* prompt_and_read_input - fucntion that displays a prompt for user input,
* and reads it.
*@input: pointer to the input string
*@len: pointer to the BUFFER_SIZE
*Return: dynamically allocated input string
*/
char *prompt_and_read_input(char **input, size_t *len)
{
	ssize_t read;
	*input = NULL;
	*len = BUFFER_SIZE;

	printf("Top-Shell:€ ");
	read = getline(input, len, stdin);
	if (read == -1)
	{
		if (read == EOF)
		{
			printf("\n");
			free(*input);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("getLine\n");
			free(*input);
			exit(EXIT_FAILURE);
		}
	}
	return (*input);
}
