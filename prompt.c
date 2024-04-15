#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char **parse(char *input);

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	char **command;

	while (1)
	{
		printf("€ ");
		read = getline(&input, &len, stdin);

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

		command = parse(input);
		if (command != NULL)
		{
			for (int i = 0; command[i] != NULL; i++)
				printf("Token %d: %s\n", i, command[i]);

			for (int i = 0; command[i] != NULL; i++)
				free(command[i]);
			free(command);
		}
		else
			printf("No command found.\n");
	}
	free(input);
	return (0);
}
