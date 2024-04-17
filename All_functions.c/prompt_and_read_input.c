#include "main.h"


char *prompt_and_read_input(char **input, size_t *len)
{
	ssize_t read;

	printf("Top-Shell:€ ");
	read = getline(input, len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("getLine\n");
			exit(EXIT_FAILURE);
		}
	}
	return (*input);
}
