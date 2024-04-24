#include "main.h"

/**
 * get_path - Function that fetches the PATH global variable
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

/**
 * find_path - Function that finds the full path of a given command.
 * @command: The command for which it's needed to find the full path
 * Return: The full path of the command if found or NULL otherwise
 */
char *find_path(char *command)
{
	char *path_copy, *path_directory, *full_command_path = NULL;

	path_copy = strdup(get_path());
	if (path_copy == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	path_directory = strtok(path_copy, ":");

	while (path_directory != NULL)
	{
		full_command_path = malloc(strlen(path_directory) + strlen(command) + 2);
		if (full_command_path == NULL)
			_perror("malloc");

		sprintf(full_command_path, "%s/%s", path_directory, command);

		if (access(full_command_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_command_path);
		}
		free(full_command_path);
		path_directory = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}


