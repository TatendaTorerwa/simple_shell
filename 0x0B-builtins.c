#include "main.h"


/**
 * handle_hash_character - remove everything after the # character.
 * @user_input: buffer and user input to remove from.
 * Return: void.
 */
void handle_hash_character(char *user_input)
{
	int position;

	for (position = 0; user_input[position] != '\0'; position++)
	{
		if (user_input[position] == '#')
		{
		user_input[position] = '\0';
		break;
		}
	}
}


/**
 * handle_cd_command - handle the cd command.
 * @cmd: the command to be parsed.
 * @error_no: the status of the last command parsed.
 * Return: 0 on success.
 */
int handle_cd_command(char **cmd, __attribute__((unused))int error_no)
{
	int value = -1;
	char cwd[PATH_MAX];

	/* If no argument is passed, change to the home directory. */
	if (cmd[1] == NULL)
	{
		value = chdir(getenv("HOME"));
	}

	/* If the argument is "-", change to the previous directory. */
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}

	/* Otherwise change to the directory passed as an argument. */
	else
	{
		value = chdir(cmd[1]);
	}

	/* Check if the directory was changed successfully. */
	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}

	/* If change is successful, update the working directory. */
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}


/**
 * handle_echo_command - execute the echo builtin.
 * @st: the status of the last command executed.
 * @cmd: the command to be parsed.
 * Return: 1 on success.
 */
int handle_echo_command(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	/* Check if the argument is "$?". */
	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_signed_number(st);
		PRINT_TO_STDOUT("\n");
	}

	/* Check if the argument is "$$". */
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_unsigned_number(pid);
		PRINT_TO_STDOUT("\n");
	}

	/* Check if the argument is the "$PATH" environment variable. */
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = get_enviro_value("PATH");
		PRINT_TO_STDOUT(path);
		PRINT_TO_STDOUT("\n");
		free(path);
	}

	/* Otherwise treat command as a regular echo command.*/
	else
	{
		return (print_echo(cmd));
	}

	return (1);
}


/**
 * handle_exit_command - execute the exit builtin.
 * @cmd: the command to be parsed.
 * @user_input: the user input to be freed.
 * @argv: the name of the program.
 * @c: the number of times the shell has looped.
 * Return: void.
 */
void  handle_exit_command(char **cmd, char *user_input, char **argv, int c)
{
	int status, i = 0;

	/* Check if there is no argument after the "exit" command. */
	if (cmd[1] == NULL)
	{
		free(user_input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	/* Check if the argument is a number. */
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			print_error(argv, c, cmd);
			break;
		}

		else
		{
			/* If argument is integer, convert. */
			status = _atoi(cmd[1]);

			/* Free allocated memory and exit. */
			free(user_input);
			free(cmd);
			exit(status);
		}
	}
}

