#include "header.h"

/**
* sigint_handler - function that handles the SIGINT(CTRL+C) signal
*					by printing a newline and prompt
*/
void sigint_handler(int sigint_)
{
	(void)sigint_;
	printf("\n$$ ");
	fflush(stdout);
}

/**
* free_string_array - Function that frees memory of an array of strings
* @array: Array of strings to be free'd
* Return: void
*/
void free_string_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**
* _realloc - function pointer that mimics the realloc() of Standard C library
* @ptr: pointer to the array that needs its memory reallocated
* @old_size: size of the array before the reallocated memory
* @new_size: size of the array expected after the reallocation
* Return: void
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr = NULL;
	char *old_ptr, *new_ptr_char;
	size_t copy_size, i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	new_ptr_char = new_ptr;

	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;

	for (i = 0; i < copy_size; ++i)
	{
		new_ptr_char[i] = old_ptr[i];
	}

	free(ptr);
	return (new_ptr);
}

/**
* check_realloc - function that handles cases of _realloc failure
* @array: array of wich the reallocation has failed
* Return: 0 on success
*/
int check_realloc(char **array)
{
	if (array == NULL)
	{
		free_string_array(array);
		perror("realloc");
		return (-1);
	}
	return (0);
}

/**
* check_malloc - function that handles cases of malloc failure
* @array: array of wich the allocation has failed
* Return: 0 on success
*/
int check_malloc(char **array)
{
	if (array == NULL)
	{
		perror("malloc");
		return (-1);
	}
	return (0);
}
