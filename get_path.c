#include "main.h"

/**
 * parse - Function that split the input strings.
 * @input: pointer of char strings
 * Return: NULL or array of pointers.
*/
const char *get_path()
{
	char **env;

	for(env = environ; environ != NULL; env++)
	{
		if(strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
	}
	return (0);
}
