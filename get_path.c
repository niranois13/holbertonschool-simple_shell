#include "main.h"

/**
 * get_path - Function that fetch the PATH global variable
 * from the environ global variable.
 * Return: 0
*/
const char *get_path()
{
	char **env;

	for (env = environ; environ != NULL; env++)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
	}
	return (0);
}
