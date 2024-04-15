#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

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
	}
	free(input);
	return (0);
}
