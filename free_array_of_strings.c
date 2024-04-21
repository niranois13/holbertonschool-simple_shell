#include "main.h"

/**
 * free_string_array - Function that frees memory for an array of strings
 * @command: Array of strings
 * Return: void
 */

void free_string_array(char **array)
{
	int i;

	for(i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
