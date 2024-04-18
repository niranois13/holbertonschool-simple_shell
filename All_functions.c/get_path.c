#include "main.h"

extern char **environ;

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
