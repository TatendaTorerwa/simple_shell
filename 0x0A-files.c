#include "main.h"


/**
 * extract_command_from_file - read commands from a file.
 * @filename: the name of the file to read from.
 * @argv: the name of the program.
 * Return: void.
 */
void extract_command_from_file(char *filename, char **argv)
{
	int count = 0;
	char *line_read = NULL;

	FILE *file_pointer;
	size_t line_length = 0;

	/* Open the file in read mode. */
	file_pointer = fopen(filename, "r");

	/* Check if the file exists. */
	if (file_pointer == NULL)
	{
		exit(EXIT_FAILURE);
	}

	/* Read the file line by line. */
	while ((getline(&line_read, &line_length, file_pointer)) != -1)
	{
		count++;
		execute_file_commands(line_read, count, file_pointer, argv);
	}

	/* Free the line to avoid memory leaks. */
	if (line_read)
	{
		free(line_read);
	}

	/* Close the file and exit. */
	fclose(file_pointer);
	exit(EXIT_SUCCESS);
}


/**
 * process_file_and_exit - process the file commands and exit.
 * @f_line: the line to be processed.
 * @tokenized_cmd: the command to be processed.
 * @filename: the name of the file to read from.
 * Return: void.
 */
void process_file_and_exit(char **tokenized_cmd, char *f_line, FILE *filename)
{
	int status;
	int position = 0;

	/* Check if the command is NULL and exit with error. */
	if (tokenized_cmd[1] == NULL)
	{
		free(f_line);
		free(tokenized_cmd);
		fclose(filename);
		exit(errno);
	}

	/* Check if the command is a number. */
	while (tokenized_cmd[1][position])
	{
		if (_isalpha(tokenized_cmd[1][position]) < 0)
		{
			perror("illegal number");
		}
	}

	status = _atoi(tokenized_cmd[1]);

	/* Avoid memory leaks. */
	free(f_line);
	free(tokenized_cmd);

	/* Close the file and exit with the status. */
	fclose(filename);
	exit(status);
}


/**
 * execute_file_commands - execute commands from a file.
 * @f_line: the line to be processed.
 * @count: execution count.
 * @f_name: the name of the file to read from.
 * @argv: the name of the program.
 * Return: void.
 */
void execute_file_commands(char *f_line, int count, FILE *f_name, char **argv)
{
	int status = 0;
	char **tokenized_command;

	tokenized_command = parse_the_command(f_line);

	/* Check if the command is exit. */
	if (_strncmp(tokenized_command[0], "exit", 4) == 0)
	{
		process_file_and_exit(tokenized_command, f_line, f_name);
	}

	/* Check if the command is a built-in command like cd or echo, etc. */
	else if (check_for_builtins(tokenized_command) == 0)
	{
		status = handle_builtin_command(tokenized_command, status);
		free(tokenized_command);
	}

	/* Or if it's not a built-in command, execute it as an external command.*/
	else
	{
		status = execute_the_command(tokenized_command, f_line, count, argv);
		free(tokenized_command);
	}
}

