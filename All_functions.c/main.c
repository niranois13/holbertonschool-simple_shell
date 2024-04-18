#include "main.h"

#define BUFFER_SIZE 1024

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	char **command;
	int i;
	char **env;
	char *command_found = NULL;

	while (1)
	{
		prompt_and_read_input(&input, &len);

		command = parse(input);
		if (command != NULL)
		{
			if (strcmp(command[0], "exit") == 0)
			{
				free(command[0]);
				free(command);
				free(input);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(command[0], "env") == 0)
			{
				for (env = environ; *env != NULL ; env++)
				{
					printf("%s", *env);
				}
			}
			for (i = 0; command[i] != NULL; i++)
				printf("Token %d: %s\n", i, command[i]);

			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);
				if (command_found != NULL)
				{
					execute_command(command_found, command);
				}
				else
				{
					printf("Command not found in path.\n");
				}
			}
			free(command_found);

			for (i = 0; command[i] != NULL; i++)
				free(command[i]);
			free(command);
		}
		else
			printf("No command found.\n");
	}
	free(input);

	return (0);
}
