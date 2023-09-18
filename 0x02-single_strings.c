#include "main.h"


/**
 * _strlen - calculates the length of a string.
 * @s: the string to be measured.
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}

	return (i);
}


/**
 * _puts - prints a string to standard output.
 * @str: the string to be printed.
 * return: void.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}


/**
 * _strchr - find a character in a string.
 * @s: the string to be searched.
 * @c: the character to be found.
 * Return: a pointer to the first occurence of the character.
 */
char *_strchr(char *s, char c)
{

	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return (s);
}


/**
 * _strcpy - copies a string from source to destination.
 * @dest: the destination of the copied string.
 * @src: the source of the string to be copied.
 * Return: the destination of the copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	/* Loop thru each char in src until the null terminator '\0' is found.*/
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - joins two strings together.
 * @des: the string to be appended to.
 * @src: the string to be appended.
 * Return: a pointer to dest + src strings.
 */
char *_strcat(char *des, char *src)
{
	char *s = des;

	/* Move dest pointer to end of the string. */
	while (*des != '\0')
	{
		des++;
	}

	/* Copy chars from src to dest until end of src. */
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}

	*des = '\0';
	return (s);
}

