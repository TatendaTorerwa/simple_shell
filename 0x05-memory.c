#include "main.h"


/**
 * free_enviro - to free the environment variables.
 * @env: the environment variables.
 * Return: void.
 */
void free_enviro(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}


/**
 * allocate_to_array -  uses malloc to create space for an array.
 * @size: the size of the array to be created.
 * Return: void.
 */
void *allocate_to_array(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	a = malloc(size);
	if (a == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}


/**
 * free_all_pointers - free both array and character pointers.
 * @cmd: the pointer to the array of pointers.
 * @line: the pointer to the characters.
 * Return: void.
 */
void free_all_pointers(char **cmd, char *line)
{
	/* Free the memory allocated. */
	free(cmd);
	free(line);

	/* Set the pointers to NULL. */
	cmd = NULL;
	line = NULL;
}


/**
 * memory_copy - copies a memory byte from source to destination.
 * @dest: a pointer to the destination of the copied memory.
 * @src: a pointer to the source of the memory to be copied.
 * @n: the number of bytes to be copied.
 * Return: a void pointer to the destination of the copied memory.
 */
char *memory_copy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}


/**
 * *re_allocate - to reallocate a memory block using malloc and free.
 * @ptr: a pointer to the memory previously allocated.
 * @old_size: the size of the allocated space for ptr.
 * @new_size: the new size to allocate.
 * Return: a pointer to the new memory block, or NULL for any failures.
 */
void *re_allocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *final_result;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	final_result = malloc(new_size);

	if (final_result == NULL)
	{
		return (NULL);
	}

	if (ptr == NULL)
	{
		fill_the_array(final_result, '\0', new_size);
		free(ptr);
	}

	else
	{
		memory_copy(final_result, ptr, old_size);
		free(ptr);
	}
	return (final_result);
}

