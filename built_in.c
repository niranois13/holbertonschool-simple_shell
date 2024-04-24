#include "main.h"

/**
 * built_in - function that handle built-in commands like "exit" and "env"
 * and the executable commands from the environement passed as first argument
 * @command: pointer to an array of strings
 * Return: succes or 0
*/
int built_in(char **command, int *exit_status)
{
	char **env;
	int user_exit_code;

	if (strcmp(command[0], "exit") == 0 && command[1] == NULL)
	{
		free_string_array(command);
		exit(*exit_status);
	}
	else if (strcmp(command[0], "exit") == 0 && command[1] != NULL)
	{
		user_exit_code = atoi(command[1]);
		free_string_array(command);
		exit(user_exit_code);
	}
	
	if (strcmp(command[0], "env") == 0)
	{
		for (env = environ; *env != NULL ; env++)
			printf("%s\n", *env);
	}
	return (0);
}
