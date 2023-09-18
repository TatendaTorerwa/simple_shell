#include "main.h"


/**
 * _atoi - convert a string to an integer.
 * @s: the string to be converted.
 * Return: the converted integer.
 */
int _atoi(char *s)
{
	int position;
	int integer_result;
	int sign;
	int i;

	position = 0;
	sign = 1;
	integer_result = 0;

	/* Handle characters that are not digits, and also the sign. */
	while ((s[position] < '0' || s[position] > '9') && (s[position] != '\0'))
	{
		if (s[position] == '-')
		{
			sign *= -1;
		}
		position++;
	}

	/* Process the digits of the string. */
	i = position;
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer_result = (integer_result * 10) + sign * ((s[i]) - '0');
		i++;
	}
	return (integer_result);
}


/**
 * _isalpha - check if the character specified is an alphabet.
 * @c: the character to be checked.
 * Return: 1 if true, 0 if not alphabet.
 */
int _isalpha(int c)
{
	/* Check if character is within the range (a-z) or (A-Z) using ASCII. */
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}

	/* In case of a character that falls outside of the range. */
	else
	{
		return (0);
	}
}


/**
 * int_length - calculates the length of an integer.
 * @n: the integer to be measured.
 * Return: the length of the integer.
 */
int int_length(int n)
{
	int len = 0;

	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}


/**
 * _putchar - writes a character to standard output.
 * @c: the character to be written.
 * Return: 1 on success, or -1 for any errors.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _itoa - converts an integer to a string.
 * @n: the integer to be converted.
 * Return: the converted string.
 */
char *_itoa(unsigned int n)
{
	char *str;
	int _length = 0;
	int i = 0;

	/* Calculate the length of the integer when converted to a string. */
	_length = int_length(n);

	/* Allocate memory for the string. */
	str = malloc(_length + 1);

	/* Check if the memory allocation succeeded. */
	if (!str)
	{
		return (NULL);
	}

	/* Initialize the string with a null terminator. */
	*str = '\0';

	/* Convert integer to string by extracting digits, right to left. */
	while (n / 10)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	/* Add the last digit to our string. */
	str[i] = (n % 10) + '0';

	/* Now reverse for correct order. */
	reverse_the_array(str, _length);
	str[i + 1] = '\0';
	return (str);
}

