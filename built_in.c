#include "main.h"

/**
 * built_in - function that handle built-in commands like "exit" and "env"
 * and the executable commands from the environement passed as first argument
 * @command: pointer to an array of strings
 * Return: succes or 0
*/
int built_in(char **command, int flag)
{
	char **env;

	if (strcmp(command[0], "exit") == 0)
	{
		free_string_array(command);
		if (flag == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(errno);
		}

	}
	if (strcmp(command[0], "env") == 0)
	{
		for (env = environ; *env != NULL ; env++)
			printf("%s\n", *env);
	}
	if (*command[0] != '\0' && access(command[0], X_OK) == 0)
		execute_command(command[0], command);

	return (1);
}
