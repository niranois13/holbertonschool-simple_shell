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

	while (1)
	{
		prompt_and_read_input(&input, &len);
		if (*input == '\n' || *input == ' ')
		{
			free(input);
			continue;
		}
		command = parse(input);
		if (command != NULL)
		{
			if ((access(command[0], X_OK) == 0) | (strcmp(command[0], "exit") == 0)
			 | (strcmp(command[0], "env") == 0))
				built_in(command);
			else if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);
				if (command_found != NULL)
					execute_command(command_found, command);
				free(command_found);
			}
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
