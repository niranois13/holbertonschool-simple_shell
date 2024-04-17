#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * find_path - Function that finds the full path of a given command.
 * @command: The command for wich to find the full path
 * Return: The full path of the command if found or NULL if not found
 */
char *find_path(char *command)
{
	char *path_copy = NULL; /*copie de la variable PATH de l'environnement*/
	char *path_directory = NULL; /* string qui va stocker chaque nouveau directory (tokenisé)*/
	char *full_command_path = NULL; /*string qui va stoquer l'ensemble des directory tokenisé plus le nom de la commande passée en input par l'utilisateur */

	path_copy = strdup(getenv("PATH")); /*copie de la variable env PATH*/
	if (path_copy == NULL)
	{
		free(path_copy); /*si echec du strdup on libère la mémoire*/
		return (NULL);
	}

	path_directory = strtok(path_copy, ":"); /*tokenisation du premier directory de la variable PATH*/

	while (path_directory != NULL)/*parse le PATH pour extraire tout les dir jusqu'à un match avec la commande utilisateur*/
	{
		full_command_path = malloc(strlen(path_directory) + strlen(command) + 2); /*Alloc de la mémoire pour stocker tous les dir tokénisés plus la commande plus 2 char pour le / et le \0 de fin*/

		if (full_command_path == NULL)
		{
			free(full_command_path);
			printf("Error: failed to allocate memory"); /*si echec free memory + print error message*/
			return (NULL);
		}
		sprintf(full_command_path, "%s/%s", path_directory, command); /*fonction qui permet remplir full_command_path avec les dir tokenisés plus le séparateur / suivi de la commande utilisateur*/
		/*printf("%s\n", full_command_path);*/

		if (access(full_command_path, X_OK) == 0) /*fonction qui check si la variable qu'on vient de créer avec le sprintf est un fichier executable et si on a la permission, si access() = 0, alors c'est qu'il y a eu match */
		{
			free(path_copy); /*on peut alors libérer la mémoire de path copy*/
			printf("%s\n", full_command_path); /*printf juste pour tester pour imprimer full_command_path dans notre shell*/
			return (full_command_path); /*comme on a trouvé notre commande dans le path, on la renvoie au main.c*/
		}
		free(full_command_path); /*libère comme d'hab*/
		path_directory = strtok(NULL, ":"); /*on tokenise le prochain dir du PATH*/
	}
	printf("Error: command not found\n"); /*si on arrive à cette étape c'est qu'on a pas trouvé la commande donc on imprime le message d'erreur*/
	return (NULL);
}
