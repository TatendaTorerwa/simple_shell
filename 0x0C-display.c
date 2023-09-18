#include "main.h"


/**
 * print_echo - execute the echo builtin command.
 * @cmd: the parsed command.
 * Return: 1 on success, or -1 for any failures.
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	/* Create a child process. */
	pid = fork();

	/* In the child process... */
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}

	/* Check if the fork failed. */
	else if (pid < 0)
	{
		return (-1);
	}

	/* In the parent process... */
	else
	{
		do {
			/* Wait for the child process to terminate. */
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}


/**
 * display_help - display the help file.
 * @cmd: the parsed command.
 * @error_status: the status of the last command.
 * Return: 0 on success, or -1 for any failures.
 */
int display_help(char **cmd, __attribute__((unused))int error_status)
{
	int file_name;
	int file_write_result;
	int read_bytes = 1;
	char c;

	/* Open specified file in read-only mode. */
	file_name = open(cmd[1], O_RDONLY);

	/* Check if the file failed to open. */
	if (file_name < 0)
	{
		perror("Error");
		return (0);
	}

	/* Read the file and write to standard output. */
	while (read_bytes > 0)
	{
		read_bytes = read(file_name, &c, 1);
		file_write_result = write(STDOUT_FILENO, &c, read_bytes);
		if (file_write_result < 0)
		{
			return (-1);
		}
	}

	_putchar('\n');
	return (0);
}


