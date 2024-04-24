#include "header.h"

/**
 * built_in - function that handle built-in commands like "exit" and "env"
 * and the executable commands from the environement passed as first argument
 * @command: pointer to an array of strings
 * Return: succes or 0
*/
int built_in(char **command)
{
	char **env;

	if (strcmp(command[0], "exit") == 0)
	{
		free_string_array(command);
		exit(errno);
	}
	if (strcmp(command[0], "env") == 0)
	{
		for (env = environ; *env != NULL ; env++)
			printf("%s\n", *env);
		return (0);
	}

	return (1);
}
