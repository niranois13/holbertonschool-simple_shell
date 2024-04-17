#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
* main - Entry point
*
* Description: Fonction qui serivira de base pour notre Shell,
*				 on y instaure un prompt de batard.
*
* Return: void
*/
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("€ ");
		read = getline(&input, &len, stdin);

		if (read == EOF)
		{
			printf("\n");
			free(input);
			exit(EXIT_FAILURE);
		}

		if (read == -1)
		{
			free(input);
			perror("getLine\n");
			exit(EXIT_FAILURE);
		}
		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(input, "exit\n") != 0)
		{
			printf(":( Command not found: %s", input);
		}
	}
	free(input);

	return (0);
}
