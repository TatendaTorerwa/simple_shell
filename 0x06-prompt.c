#include "main.h"


/**
 * display_the_prompt - display the simple shell prompt.
 * Return: void.
 */
void display_the_prompt(void)
{
	PRINT_TO_STDOUT("#cisfun$ ");
}


/**
 * own_getline - a custom getline function.
 * Return: a pointer to the buffer containing the user input.
 */
char *own_getline(void)
{
	char current_char = 0;
	int position, read_status;
	int buffer_size = BUFFER_CAPACITY;
	char *input_buffer = malloc(buffer_size);

	if (input_buffer == NULL)
	{
		free(input_buffer);
		return (NULL);
	}

	for (position = 0; current_char != EOF && current_char != '\n'; position++)
	{
		fflush(stdin);
		read_status = read(STDIN_FILENO, &current_char, 1);
		if (read_status == 0)
		{
			free(input_buffer);
			exit(EXIT_SUCCESS);
		}
		input_buffer[position] = current_char;
		if (input_buffer[0] == '\n')
		{
			free(input_buffer);
			return ("\0");
		}
		if (position >= buffer_size)
		{
			input_buffer = re_allocate(input_buffer, buffer_size, buffer_size + 1);
			if (input_buffer == NULL)
			{
				return (NULL);
			}
		}
	}
	input_buffer[position] = '\0';
	handle_hash_character(input_buffer);
	return (input_buffer);
}


/**
 * handle_control_c - to handle the ctrl + c signal.
 * @r_signal: the signal number received.
 * Return: void.
 */
void handle_control_c(int r_signal)
{
	if (r_signal == SIGINT)
	{
		PRINT_TO_STDOUT("\n#cisfun$ ");
	}
}


/**
 * check_delimiter_characters - to check for delimiter characters.
 * @c: the character to be checked.
 * @str: the string to be checked against.
 * Return: 1 if the character is a delimiter, 0 if it's not.
 */
unsigned int check_delimiter_characters(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
		{
			return (1);
		}
	}
	return (0);
}

