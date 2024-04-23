#include "main.h"
#define BUFFER_SIZE 1024

/**
* launch_prompt_1 - fucntion that launch our prompt in interractive mode
* and reads it.
*@args: pointer to the input string
*Return: 1 if succesfull or 0 if fails to launch
*/
int launch_prompt_1(char **args)
{
	char *input, *command_found = NULL;
	size_t len = 0;
	char **command = NULL;
	int flag_status = EXIT_SUCCESS;

	while (1)
	{
		prompt_and_read_input_1(&input, &len);
		command = parse(input);
		if (command != NULL && command[0] != NULL)
		{
			if ((access(command[0], X_OK) == 0) | (strcmp(command[0], "exit") == 0)
			| (strcmp(command[0], "env") == 0))
			{
				built_in(command, flag_status);
				free_string_array(command);
				continue;
			}
			if (*command[0] != '\0')
			{
				command_found = find_path(command[0]);

				if (command_found != NULL)
					execute_command(command_found, command);
				else
					dprintf(STDERR_FILENO, "%s: No such file or directory\n", args[0]);
						flag_status = update_exit_status(flag_status);

				free(command_found);
			}
			free_string_array(command);
		}
	}
	free(input);
	return (0);
}
