#include "main.h"


/**
 * check_for_builtins - checks if the command specified is a builtin.
 * @cmd: the command to be checked.
 * Return: 0 if true, -1 if it's not a builtin.
 */
int check_for_builtins(char **cmd)
{
	int i = 0;

	/* Define a structure to hold the builtin functions. */
	builtin_function b_func[] = {
		{"help", NULL},
		{"cd", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	/* Check if the command is NULL. */
	if (*cmd == NULL)
	{
		return (-1);
	}

	/* Loop through the builtin functions. */
	while ((b_func + i)->command)
	{
		if (_strcmp(cmd[0], (b_func + i)->command) == 0)
		{
			return (0);
		}
		i++;
	}
	return (-1);
}


/**
 * construct_path - constructs the path to the executable.
 * @token: the command to be searched for.
 * @value: the value of the $PATH.
 * Return: a pointer to the complete constructed path.
 */
char *construct_path(char *token, char *value)
{
	size_t path_length;
	char *complete_path;

	path_length = _strlen(value) + _strlen(token) + 2;
	complete_path = malloc(sizeof(char) * path_length);

	/* Check if malloc was successful. */
	if (complete_path == NULL)
	{
		return (NULL);
	}

	/* Initialize the memory. */
	memset(complete_path, 0, path_length);

	/* Construct the complete path. */
	complete_path = _strcat(complete_path, value);
	complete_path = _strcat(complete_path, "/");
	complete_path = _strcat(complete_path, token);

	return (complete_path);
}


/**
 * handle_builtin_command - to handle builtin commands.
 * @cmd: the command to be handled.
 * @er: the status of the last command executed.
 * Return: 0 on success, or -1 for any failures.
 */
int handle_builtin_command(char **cmd, int er)
{
	int i = 0;

	/* Define a structure to keep the builtin functions. */
	 builtin_function b_func[] = {
		{"help", display_help},
		{"cd", handle_cd_command},
		{"env", enviro},
		{"history", show_history},
		{"echo", handle_echo_command},
		{NULL, NULL}
	};

	/* Try loop through the builtin functions to find a match and execute. */
	while ((b_func + i)->command)
	{
		if (_strcmp(cmd[0], (b_func + i)->command) == 0)
		{
			return ((b_func + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}

