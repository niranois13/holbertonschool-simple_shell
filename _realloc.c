#include "main.h"

/**
* _realloc - function that replicates realloc()
* @ptr: pointer to the array to realloc memory for
* @old_size: size of the previously allocated memory
* @new_size: size of the newly allocated memory
*/
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t min_size;
	size_t i;

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (ptr == NULL)
	{
	   return malloc(size);
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return NULL;

	min_size = *(size_t *)ptr < size ? *(size_t *)ptr : size;

	for (i = 0; i < min_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return new_ptr;
}




