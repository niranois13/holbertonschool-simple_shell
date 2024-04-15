#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
/* Une dclaration de la fonction parse, pour la déclarer ici */
char **parse(char *input);

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	char **command;

/* Genre 'tant que c'est vrai' donc tout le temps */
	while (1)
	{
	/* On affiche le prompt */
		printf("€ ");
	/* on définie un signed int 'read' qui correspond au nombre de caractères imprimé par
	getline en fonction de l'input sur stdin:
	-stdin: correspond à l'input standard: principalement le flux de
		ce qui est écrit dans le prompt par l'utilisateur
	-&input: l'adresse de l'espace mémoire alloué par getline qui conient l'input entré par
		l'utilisateur
	-&len: la taille de l'espace mémoire alloué à l'input par getline */
		read = getline(&input, &len, stdin);

	/* Si read vaut -1, c'est que ça a foiré*/
		if (read == -1)
		{
			/* feof est une fonction qui permet de déterminer le End Of File de ce qu'on envoie dans le stdin
			concrètement: quand on force l'arrêt du programme avec ctrl+d, on envoie le signel EOF.
			On libère la mémoire allouée pour l'input et on sort avec exit(SUCCESS) car on a souhaité sortir, c'est pas une erreur */
			if (feof(stdin))
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
		/* Si on sort avec quoi que ce soit d'autre que ctrl+d, c'est qu'il y a un souci,
		on imprime cette erreur dans les logs et on envoie le signal exit(FAILURE) */
			else
			{
				free(input);
				perror("getLine\n");
				exit(EXIT_FAILURE);
			}
		}

	/*L'array command, définie plus haut, est désormais définit comme la valeur
	de retour de la fonction parse().

	Ce qui suit sert de test pour vérifier que la fonction parse fonctionne correctement.*/
		command = parse(input);
	/*Tant que command n'est pas NULL...*/
		if (command != NULL)
		{
		/* On parcourt l'array jusqu'au bout et on imprime les éléments
		chaque élément correspond à un token, un mot découpé dans l'input par la fonction parse*/
			for (int i = 0; command[i] != NULL; i++)
				printf("Token %d: %s\n", i, command[i]);
		/* On libère la mémoire de chaque élément, puisque nous ne nous en servons plus*/
			for (int i = 0; command[i] != NULL; i++)
				free(command[i]);
		/* On libère la mémoire de l'array, pareil, on s'en sert plus*/
			free(command);
		}
		/* Si quelque chose a foiré, on imprime ça*/
		else
			printf("No command found.\n");
	}
/* On libère la mémoire allouée pour stocker l'input*/
	free(input);
	return (0);
}
