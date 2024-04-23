#include "main.h"

/**
 * get_path - Function that fetches the PATH global variable
 * from the environ global variable.
 * Return: 0
*/
char *const *get_env()
{
	char **env = NULL;

	for (env = environ; *env != NULL ; env++)
	{
		;
	}
	return (env);
}
