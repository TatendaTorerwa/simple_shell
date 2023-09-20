#include "main.h"


/**
 * main - the entry point of the simple shell program.
 * @argc: the number of arguments passed to shell the program.
 * @argv: the arguments passed to the shell program.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *user_input, **cmd;
	int status = 1;
	int exec = 0;
	int c = 0;

	if (argv[1] != NULL)
		extract_command_from_file(argv[1], argv);

	signal(SIGINT, handle_control_c);

	while (status)
	{
		c++;
		if (isatty(STDIN_FILENO))
			display_the_prompt();

		user_input = own_getline();
		if (user_input[0] == '\0')
			continue;

		history_file(user_input);
		cmd = parse_the_command(user_input);
		if (_strcmp(cmd[0], "exit") == 0)
			handle_exit_command(cmd, user_input, argv, c);

		else if (check_for_builtins(cmd) == 0)
		{
			exec = handle_builtin_command(cmd, exec);
			free_all_pointers(cmd, user_input);
			continue;
		}

		else
			exec = execute_the_command(cmd, user_input, c, argv);

		free_all_pointers(cmd, user_input);
	}
	return (status);
}


