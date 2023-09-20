#include "main.h"


/**
 * enviro - display the environment variables.
 * @cmd: the command to be parsed.
 * @er: the status of the last command executed.
 * Return: 0 on success.
 */
int enviro(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
 * get_enviro_value - gets the value of an environment variable from environ.
 * @name: the name of the environment variable.
 * Return: a pointer to the value of the environment variable.
 */
char *get_enviro_value(char *name)
{
	size_t name_length;
	size_t env_length;
	char *value;
	int position;
	int index;
	int i;

	name_length = _strlen(name);

	for (position = 0; environ[position]; position++)
	{
		if (_strncmp(name, environ[position], name_length) == 0)
		{
			env_length = _strlen(environ[position]) - name_length;
			value = malloc(sizeof(char) * env_length);

			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			i = 0;
			for (index = name_length + 1; environ[position][index]; index++, i++)
			{
				value[i] = environ[position][index];
			}
			value[i] = '\0';

			return (value);
		}
	}

	return (NULL);
}


/**
 * create_enviro_array - creates an array of environment variables.
 * @envi: the array to be created.
 * Return: void.
 */
void create_enviro_array(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		envi[i] = _strdup(environ[i]);
	}

	envi[i] = NULL;
}


