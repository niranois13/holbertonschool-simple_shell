#include "main.h"

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
			printf("%s", *env);
		}
	}
	return (0);
}
