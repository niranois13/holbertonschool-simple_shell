#include "main.h"
/**
 * built_in - function that handle built-in commands like "exit" and "env"
 * @command: pointer to array of char
 * Return: succes or 0
*/

int built_in(char **command)
{
	char **env;

	if (strcmp(command[0], "exit") == 0)
	{
		free(command[0]);
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(command[0], "env") == 0)
	{
		for (env = environ; *env != NULL ; env++)
		{
			printf("%s\n", *env);
		}
	}
	return (0);
}
