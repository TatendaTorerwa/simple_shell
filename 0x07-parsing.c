#include "main.h"


/**
 * search_path -  to search for a command in the $PATH.
 * @cmd: the command to be searched for.
 * Return: 0 on success, or 1 for any failures.
 */
int search_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = get_enviro_value("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = construct_path(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}


/**
 * parse_the_command - to parse the user input.
 * @input: the input from the user.
 * Return: a pointer to the parsed command.
 */
char **parse_the_command(char *input)
{
	char **reserved_space;
	char *single_token;
	int i, buffsize = BUFFER_CAPACITY;

	if (input == NULL)
	{
		return (NULL);
	}

	reserved_space = malloc(sizeof(char *) * buffsize);

	if (!reserved_space)
	{
		perror("hsh");
		return (NULL);
	}

	single_token = _strtok(input, "\n ");
	for (i = 0; single_token; i++)
	{
		reserved_space[i] = single_token;
		single_token = _strtok(NULL, "\n ");
	}
	reserved_space[i] = NULL;

	return (reserved_space);
}


/**
 * execute_the_command - to execute the command from the user.
 * @cmd: the parsed command.
 * @input: the input from the user.
 * @c: the counter of the commands executed.
 * @argv: the arguments passed to the shell program.
 * Return: 0 on success, or -1 for any failures.
 */
int execute_the_command(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			search_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			display_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}


