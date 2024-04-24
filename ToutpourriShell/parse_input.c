#include "header.h"

/**
 * parse - Function that tokkenizes the input string.
 * @input: pointer to the strings
 * Return: NULL or array of arguments strings.
*/
char **parse(char *input)
{
	char **tokens = NULL;
	char *tok = NULL;
	int position = 0;
	const char *delim = " \t\n";

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		check_malloc(tokens);
	tok = strtok(input, delim);
	if (tok == NULL)
	{
		free(tokens);
		return (NULL);
	}
	while (tok != NULL)
	{
		tokens[position] = strdup(tok);
		if (tokens[position] == NULL)
		{
			free_string_array(tokens);
			fprintf(stderr, "Failed to duplicate token\n");
			return (NULL);
		}
		position++;

		tokens = _realloc(tokens, position * sizeof(char *),
		(position + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			free_string_array(tokens);
			check_realloc(tokens);
		}
		tok = strtok(NULL, delim);
	}
	free(input);
	tokens[position] = NULL;
	return (tokens);
}
