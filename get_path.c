#include "main.h"

/**
 * get_path - Function that split the input strings.
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
