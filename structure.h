#ifndef STRUCTURE_H
#define STRUCTURE_H


/**
 * struct builtin_functions - define struct for built-in functions.
 * @command: a pointer to a char, the built-in to handle.
 * @fun: the function to execute when the built-in is handled.
 */
typedef struct builtin_functions
{
	char *command;
	int (*fun)(char **line, int er);
} builtin_function;


#endif

