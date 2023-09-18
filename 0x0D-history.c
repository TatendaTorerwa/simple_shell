#include "main.h"


/**
 * history_file - file to store history of user input.
 * @user_input: the input from the user.
 * Return: 1 on success, or -1 for any failures.
 */
int history_file(char *user_input)
{
	int input_length = 0;
	ssize_t written;
	ssize_t file_descriptor;
	char *filename = ".our_shell_history";

	/* Check if the filename is NULL. */
	if (!filename)
	{
		return (-1);
	}

	/* Open the file with permissions.*/
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);

	/* Check if opening the file failed. */
	if (file_descriptor < 0)
	{
		return (-1);
	}

	/* Check if the user input is not NULL. */
	if (user_input)
	{
		while (user_input[input_length])
		{
			input_length++;
		}

		/* Write the user input to the file. */
		written = write(file_descriptor, user_input, input_length);

		if (written < 0)
		{
			return (-1);
		}
	}

	return (1);
}


/**
 * show_history - display the user input history into the history file.
 * @c: the parsed command.
 * @s: the status of the last command executed.
 * Return: 0 on success, or -1 for any failures.
 */
int show_history(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *file_name = ".our_shell_history";
	char *error_status;
	FILE *file_pointer;

	char *line = NULL;
	int count = 0;
	size_t len = 0;

	/* Open the history file for reading. */
	file_pointer = fopen(file_name, "r");
	if (file_pointer == NULL)
	{
		return (-1);
	}

	/* Read and display each line from the history file. */
	while ((getline(&line, &len, file_pointer)) != -1)
	{
		count++;
		error_status = _itoa(count);
		PRINT_TO_STDOUT(error_status);

		/* Avoid memory leaks. */
		free(error_status);

		PRINT_TO_STDOUT(" ");
		PRINT_TO_STDOUT(line);
	}

	/* Free the memory and close history file. */
	if (line)
	{
		free(line);
	}

	fclose(file_pointer);
	return (0);
}

