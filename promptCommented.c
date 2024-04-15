#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* permet à getline d'utiliser 1024 bytes, limitant les fuites mémoires*/
#define BUFFER_SIZE 1024

/**
* main - Entry point
*
* Description: Fonction qui serivira de base pour notre Shell,
*				 on y instaure un prompt de batard.
*
* Return: void
*/
int main(void)
{
	/* initialise la string entre par l'utilisateur à NULL,
	pour que l'utilisateur ait de la place*/
	char *input = NULL;

	/* initialise la longueur de l'input à 0, getline lui alouera la place
	nécessaire, dans la limite de 1024 bytes*/
	size_t len = 0;

	/* déclare un signed int de type size_t */
	ssize_t read;

	/* Tant que la situation est 'vraie', alors on parcourt la boucle */
	while (1)
	{
		/* imprime notre prompt "€" */
		printf("€ ");

		/* 'read' stocke le nombre de caractères lus par getline
			getline lit une entrée de stdin (une ligne tapée par
			l'utilisateur ou renvoyée par d'autres fonctions), la stocke dans
			le buffer attribuée, qui sera pointé par 'input'.
			&input est l'adresse de ce tampon, &len est l'adresse pointée par
			len, qui compte le nombr de caractères entrés.*/
		/* En bref, lit une ligne entrée depuis le terminal et la stocke dans
			le tampon input. La taille de ce tampon est gérée dynamiquement par
			la fonction getline() en fonction de la longueur de l'entrée.*/
		read = getline(&input, &len, stdin);

		/* Au cas où le programme s'arrête ailleurs que sur la End Of Line(EOL)
			(la fin normale du programme), la fin est executée par 'exit' */
		if (EOF != '\0')
		{
			free(input);
			exit(EXIT_FAILURE);
		}

		/* Gère une erreur au moment de l'input, en indiquant exit_failure et
			en libérant la mmoire allouée*/
		if (read == -1)
		{
			free(input);
			perror("getLine");
			exit(EXIT_FAILURE);
		}

		/* Si l'utilisateur entre 'exit' dans sont terminal, le programme
			libère la mmoire et se ferme en indiquant SUCCESS. */
		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		/*Si l'utilsiateur entre autre chose que 'exit', le programme
			lui indique que son input est inconnu. Cette ligne changera,
			à terme nous gèrerons autre chose que la commande 'exit'.
			La mémoire allouée pour input est libérée afin de pouvoir lui
			en attribuer à nouveau pour le prochain input*/
		if (strcmp(input, "exit\n") != 0)
		{
			free(input);
			printf(":( Command not found: %s", input);
		}
	}

	free(input);
	return (0);
}
