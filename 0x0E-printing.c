#include "main.h"


/**
 * print_unsigned_number - print an unsigned integer using _putchar.
 * @n: the unsigned integer to be printed.
 * Return: void.
 */
void print_unsigned_number(unsigned int n)
{
	unsigned int u_int = n;

	if ((u_int / 10) > 0)
	{
		print_unsigned_number(u_int / 10);
	}

	_putchar(u_int % 10 + '0');
}


/**
 * print_signed_number - print a signed integer using _putchar.
 * @n: the signed integer to be printed.
 * Return: void.
 */
void print_signed_number(int n)
{
	unsigned int u_int = n;

	/* Handle negative integers */
	if (n < 0)
	{
		_putchar('-');
		u_int = -u_int;
	}

	/* Recursively print the unsigned part of the number */
	if ((u_int / 10) > 0)
	{
		print_unsigned_number(u_int / 10);
	}

	_putchar(u_int % 10 + '0');
}


/**
 * display_error - display error based on user input.
 * @input: the input from the user.
 * @counter: the number of commands executed.
 * @argv: the arguments passed to the shell program.
 * Return: void.
 */
void display_error(char *input, int counter, char **argv)
{
	char *error_status;

	/* Handle case of command not found */
	PRINT_TO_STDOUT(argv[0]);
	PRINT_TO_STDOUT(": ");

	error_status = _itoa(counter);

	PRINT_TO_STDOUT(error_status);

	/* Free the memory allocated for error_status */
	free(error_status);

	PRINT_TO_STDOUT(": ");
	PRINT_TO_STDOUT(input);
	PRINT_TO_STDOUT(": not found\n");
}


/**
 *  print_error - print the error message.
 * @argv: the arguments passed to the shell program.
 * @c: the counter of the commands executed.
 * @cmd: the parsed command.
 * Return: void.
 */
void print_error(char **argv, int c, char **cmd)
{
	char *error_status = _itoa(c);

	/* Print the program name argv[0] and a separator. */
	PRINT_TO_STDOUT(argv[0]);
	PRINT_TO_STDOUT(": ");

	/* Print the error status. */
	PRINT_TO_STDOUT(error_status);
	PRINT_TO_STDOUT(": ");

	/* Print the command name cmd[0] and an error message. */
	PRINT_TO_STDOUT(cmd[0]);
	PRINT_TO_STDOUT(": Illegal number: ");
	PRINT_TO_STDOUT(cmd[1]);
	PRINT_TO_STDOUT("\n");

	/* Free the memory allocated for error_status. */
	free(error_status);
}

