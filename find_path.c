#include "main.h"

/**
 * find_path - Function that finds the full path of a given command.
 * @command: The command for wich to find the full path
 * Return: The full path of the command if found or NULL if not found
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
		{
			free(full_command_path);
			perror("malloc");
			return (NULL);
		}
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
