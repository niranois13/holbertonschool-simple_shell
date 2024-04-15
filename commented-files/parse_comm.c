#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse(char *input)
{
/* Définie un pointeur de pointeur d'array et un pointeur d'array */
	char **tokens = NULL, *tok;

/* Nous servira à parcourir notre array */
	int position = 0;

/* Définie les délimiteurs à prndre en compte: espaces, tabulation et retour à la ligne.
	Y en a d'autre mais flemme */
	const char *delim = " \t\n";

/* au cas où l'input soit une grosse daube, on renvoie NULL */
	if (input == NULL)
		return (NULL);

/* On attribue de la mémoire pour notre array tokens, en réalit seulement pour son premier élément*/
	tokens = malloc(sizeof(char *));
	/* Si notre array est une daube, on renvoie NULL */
	if (tokens == NULL)
		return (NULL);

/* Chacun des token créés par strtok, en fonction des délimiteur définis plus haut */
	tok = strtok(input, delim);
/* On parcourt l'array 'tok' jusqu'au bout*/
	while (tok != NULL)
	{
	/* On réattribue de la mémoire pour chacun des éléments de l'array */
		tokens = realloc(tokens, (position + 1) * sizeof(char *));
	/* Si l'allocation de mémoire foire, on libère toute la mémoire attribuée aux éléments de l'array
	ainsi qu'à l'array lui-même */
		if (tokens == NULL)
		{
			for (int i = 0; i < position; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			return (NULL);
		}
	/* strdup est une fonction qui permet de copier un array et d'allouer de la mémoire à sa copie.
	Si la partie allocation de mémoire semble redondante avec le realloc d'au-dessus,
	strdup vient surtout copier les éléments de l'array tok, dans l'array tokens. */
		tokens[position] = strdup(tok);
		/* si ça foire, on libère la mémoire, as usual*/
		if (tokens[position] == NULL)
		{
			for (int i = 0; i < position; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			return (NULL);
		}
		/* A ce stade, cette ligne sert à s'assurer que tok finisse bien par NULL */
		tok = strtok(NULL, delim);
		position++;
	}
	/* Là encore, on s'assure que tokens se finisse par NULL */
	tokens[position] = NULL;
	/* On renvoie l'array tokens à la fonction main */
	return (tokens);
}
