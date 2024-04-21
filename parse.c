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
	{
		perror("malloc");
		return (NULL);
	}
	tok = strtok(input, delim);
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

		tokens = realloc(tokens, (position + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			free_string_array(tokens);
			perror("realloc");
			return (NULL);
		}
		tok = strtok(NULL, delim);
	}
	free(input);
	tokens[position] = NULL;
	return (tokens);
}
