#include "main.h"

/**
 * parse - Function that tokkenises the input string.
 * @input: pointer to the strings
 * @exit_status: pointer to an int storing the exit status
 * Return: NULL or array of arguments strings.
*/
char **parse(char *input, int *exit_status)
{
	char **tokens = NULL, *tok;
	int position = 0;
	const char *delim = " \t\n";

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		_error("malloc", exit_status);
	tok = strtok(input, delim);
	if (tok == NULL)
	{
		free(input);
		free(tokens);
		return (NULL);
	}
	while (tok != NULL)
	{
		tokens[position] = strdup(tok);
		if (tokens[position] == NULL)
		{
			free_string_array(tokens);
			_error("stdrup", exit_status);
		}
		position++;
		tokens = _realloc(tokens, position * sizeof(char *),
		(position + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			free_string_array(tokens);
			_error("realloc", exit_status);
		}
		tok = strtok(NULL, delim);
	}
	free(input);
	tokens[position] = NULL;
	return (tokens);
}
