#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *input;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("€ ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			perror("getLine");
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
