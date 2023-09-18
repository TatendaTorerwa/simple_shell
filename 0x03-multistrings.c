#include "main.h"


/**
 * _strdup - duplicates a string.
 * @str: the string to be duplicated.
 * Return: a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	/* Declare variables. */
	size_t s_length;
	size_t position;
	char *dupl_string;

	s_length = _strlen(str);
	dupl_string = malloc(sizeof(char) * (s_length + 1));

	/* Check if malloc was successful. */
	if (!dupl_string)
	{
		return (NULL);
	}

	/* Copy the string from original input str to duplicate. */
	for (position = 0; position <= s_length; position++)
	{
		dupl_string[position] = str[position];
	}

	return (dupl_string);
}


/**
 * _strcmp - compares two strings.
 * @s1: the first string.
 * @s2: the second string.
 * Return: 0 if the strings match, or 1 if they don't.
 */
int _strcmp(char *s1, char *s2)
{
	/* Declare variables. */
	int position;
	int s_length1;
	int s_length2;
	int s_compare = 0;

	s_length1 = _strlen(s1);
	s_length2 = _strlen(s2);

	/* Check if strings are NULL. */
	if (s1 == NULL || s2 == NULL)
	{
		return (1);
	}

	/* Check if strings are the same length. */
	if (s_length1 != s_length2)
	{
		return (1);
	}

	/* Compare the strings. */
	for (position = 0; s1[position]; position++)
	{
		/* Check if the strings are not the same. */
		if (s1[position] != s2[position])
		{
			s_compare = s1[position] - s2[position];
			break;
		}

		/* Continue to next iteration. */
		else
		{
			continue;
		}
	}
	return (s_compare);
}


/**
 * _strtok - to split a string into tokens.
 * @str: the string to be split.
 * @delim: the delimiter (separator).
 * Return: a pointer to the first token found.
 */
char *_strtok(char *str, const char *delim)
{
	unsigned int position;
	static char *token_start;
	static char *next_token;
	/* First, handle cases where we're starting from NULL. */
	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	/* Then, loop: find the start of the next token. */
	for (position = 0; token_start[position] != '\0'; position++)
	{
		if (check_delimiter_characters(token_start[position], delim) == 0)
			break;
	}
	if (next_token[position] == '\0' || next_token[position] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + position;
	next_token = token_start;
	/* Then, loop: find the end of the token. */
	for (position = 0; next_token[position] != '\0'; position++)
	{
		if (check_delimiter_characters(next_token[position], delim) == 1)
			break;
	}
	if (next_token[position] == '\0')
		next_token = NULL;
	else
	{
		next_token[position] = '\0';
		next_token += (position + 1);
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}



/**
 * _strncpy - to copy a string.
 * @dest: the destination of the copied string.
 * @src: the source of the string to be copied.
 * @n: the number of bytes to be copied.
 * Return: the destination of the copied string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;

	/* Copy n chars from src to dest up to the first '\0'. */
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}

	/* Fill the rest of the n bytes with '\0'. */
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}

	return (dest);
}


/**
 * _strncmp - compares the amount of characters in two strings.
 * @s1: the first string.
 * @s2: the second string.
 * @n: the number of characters to be compared.
 * Return: 0 if the amount of characters match, or 1 if they don't.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	/* Check if strings are NULL. */
	if (s1 == NULL)
	{
		return (-1);
	}

	/* Compare the strings. */
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

