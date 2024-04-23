#include "main.h"
#define BUFFER_SIZE 1024

/**
* launch_prompt_2 - fucntion that launch our prompt in interractive mode
* and reads it.
*@args: pointer to the input string
*@argc_number: number of arguments
*Return: 1 if succesfull or 0 if fails to launch
*/
int launch_prompt_2(int argc_number, char **args)
{
	char *input, *command_found = NULL;
	size_t len = 0;
	char **command = NULL;
	int flag = 0;

	while (1)
	{
		prompt_and_read_input_2(&input, &len);
		command = parse(input);
		if (command != NULL && command[0] != NULL)
		{
			if ((access(command[0], X_OK) == 0) | (strcmp(command[0], "exit") == 0)
			| (strcmp(command[0], "env") == 0))
			{
				built_in(command, flag);
				free_string_array(command);
				continue;
			}
			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);

				if (command_found != NULL)
					execute_command(command_found, command);
				else
				{
					dprintf(STDERR_FILENO, "%s: %d: No such file or directory\n",
					 args[0], argc_number);
					 	flag = 1;
				}
				free(command_found);
			}
			free_string_array(command);
		}
	}
	free(input);
	return (0);
}
