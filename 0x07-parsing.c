#include "main.h"


/**
 * search_path -  to search for a command in the $PATH.
 * @cmd: the command to be searched for.
 * Return: 0 on success, or 1 for any failures.
 */
int search_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buffer;

	path = get_enviro_value("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = construct_path(*cmd, value);
		if (stat(cmd_path, &buffer) == 0)
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
	int position;
	int buffsize = BUFFER_CAPACITY;

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
	for (position = 0; single_token; position++)
	{
		reserved_space[position] = single_token;
		single_token = _strtok(NULL, "\n ");
	}
	reserved_space[position] = NULL;

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
	/* Declare error status and child process. */
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	/* Fork and create child process. */
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	/* Then execute the command. */
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			search_path(cmd);
		}

		/* Avoid memory leaks. */
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


