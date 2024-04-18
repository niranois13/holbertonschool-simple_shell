#include "main.h"

char **parse(char *input)
{
	char **tokens = NULL, *tok;
	int position = 0, i;
	const char *delim = " \t\n";

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	tok = strtok(input, delim);
	while (tok != NULL)
	{
		tokens[position] = strdup(tok);
		if (tokens[position] == NULL)
		{
			for (i = 0; i < position; i++)
				free(tokens[i]);

			free(tokens);
			return (NULL);
		}
		position++;

		tokens = realloc(tokens, (position + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			for (i = 0; i < position; i++)
				free(tokens[i]);
			
			free(tokens);
			return (NULL);
		}
		tok = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
