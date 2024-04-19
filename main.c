#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - main function of the simpleShell
 * Return: Void
*/
int main(void)
{
	char *input, *command_found = NULL;
	size_t len = 0;
	int i;
	char **command = NULL;
	signal(SIGINT, sigint_handler);

	while (1)
	{
		prompt_and_read_input(&input, &len);
		if (*input == '\n' || *input == ' ')
		{
			free(input);
			continue;
		}
		command = parse(input);
		printf("1:%s\n", command[0]);

		if (command != NULL)
		{
			built_in(command);
			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);
				printf("2:%s\n", command_found);

				if (command_found != NULL)
					execute_command(command_found, command);
			}
			for (i = 0; command[i] != NULL; i++)
				free(command[i]);
			free(command);
		}
		else
			printf("No command found.\n");
	}
	free(command_found);
	free(input);
	return (0);
}
