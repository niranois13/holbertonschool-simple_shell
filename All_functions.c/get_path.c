#include "main.h"
/**
* get_path - Function that extract the PATH from the environement.
* Return: the PATH or 0
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
