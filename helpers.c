#include "main.h"

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
		{
			return (NULL);
		}
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
* free_string_array - Function that frees memory for an array of strings
* @array: Array of strings
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
* sigint_handler - function that handles the SIGINT(CTRL+C) signal
*					by printing a newline and prompt
* @sig: signal sent by the signal function
* Return: void
*/
void sigint_handler(int sig)
{
	(void)sig;
	printf("\n$$ ");
	fflush(stdout);
}

/**
* _perror - function that handles system call failures
* @error_msg: string containing the adequat perror message
* @exit_status: pointer to an int storing the exit status
* Return: void
*/
int _perror(char *error_msg, int *exit_status)
{
	perror(error_msg);
	*exit_status = errno;
	return (-1);
}

/**
* _error - function that handles errors, except system call failures
* @error_msg: string containing the adequat error message
* @exit_status: pointer to an int storing th exit status
*/
void _error(const char *error_msg, int *exit_status)
{
	int error_exit_code;

	if (strcmp(error_msg, "Command not found") == 0)
	{
		error_exit_code = 127;
		*exit_status = error_exit_code;
	}
	else if (strcmp(error_msg, "malloc") == 0)
	{
		fprintf(stderr, "Memory allocation failed\n");
		error_exit_code = 1;
		*exit_status = error_exit_code;
	}
	else if (strcmp(error_msg, "realloc") == 0)
	{
		fprintf(stderr, "Memory reallocation failed\n");
		error_exit_code = 1;
		*exit_status = error_exit_code;
	}
	else if (strcmp(error_msg, "strdup") == 0)
	{
		fprintf(stderr, "Failed to duplicate token\n");
		error_exit_code = 1;
		*exit_status = error_exit_code;
	}
	else if (strcmp(error_msg, "getline") == 0)
	{
		fprintf(stderr, "Failed to read user input\n");
		error_exit_code = 1;
		*exit_status = error_exit_code;
	}
	else if (strcmp(error_msg, "EOF") == 0)
	{
		;
	}
}
