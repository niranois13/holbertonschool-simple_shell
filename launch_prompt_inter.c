#include "main.h"
#define BUFFER_SIZE 1024

/**
* launch_prompt - fucntion that launch our prompt in interractive mode
* and reads it.
*@input: pointer to the input string
*@len: pointer to the BUFFER_SIZE
*@command: the array of command's arguments
*@command_found: a string composed of the path/command
*Return: 1 if succesfull or 0 if fails to launch
*/
int launch_prompt_1(char **args)
{
	char *input, *command_found = NULL;
	size_t len = 0;
	char **command = NULL;

	while (1)
	{
		prompt_and_read_input_1(&input, &len);
		if (*input == '\n' || *input == ' ')
		{
			free(input);
			continue;
		}
		command = parse(input);
		if (command != NULL)
		{
			if ((access(command[0], X_OK) == 0) | (strcmp(command[0], "exit") == 0) | (strcmp(command[0], "env") == 0))
			{
				built_in(command);
				free_string_array(command);
				continue;
			}
			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);

				if (command_found != NULL)
					execute_command(command_found, command);
				else
					dprintf(STDERR_FILENO,"%s: No such file or directory\n", args[0]);
				free(command_found);
			}
			free_string_array(command);
		}
	}
	free(input);
	return(0);
}
