#include "main.h"

/**
 * parse - Function that tokkenises the input string.
 * @input: pointer to the strings
 * Return: NULL or array of arguments strings.
*/
char **parse(char *input)
{
	char **tokens = NULL, *tok;
	int position = 0;
	const char *delim = " \t\n";

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		_perror("malloc");
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
			_perror("stdrup");
			fprintf(stderr, "Failed to duplicate token\n");
		}
		position++;
		tokens = _realloc(tokens, position * sizeof(char *),
		(position + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			free_string_array(tokens);
			_perror("realloc");
		}
		tok = strtok(NULL, delim);
	}
	free(input);
	tokens[position] = NULL;
	return (tokens);
}
