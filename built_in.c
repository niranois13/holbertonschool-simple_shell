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
		printf("1:%d\n", flag);
		printf("1:%d\n", errno);
		free_string_array(command);
		if (flag == 0)
		{
			printf("2:%d\n", flag);
			printf("2:%d\n", errno);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("3:%d\n", flag);
			printf("3:%d\n", errno);
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
