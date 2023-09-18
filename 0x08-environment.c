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
	size_t nl;
	size_t vl;
	char *value;
	int i;
	int x;
	int j;

	nl = _strlen(name);

	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);

			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

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


