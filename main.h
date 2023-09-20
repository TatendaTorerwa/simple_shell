#ifndef MAIN_H
#define MAIN_H


/* Environment variable defined. */
extern char **environ;


/* Macros defined. */
#define BUFFER_CAPACITY 1024
#define PRINT_TO_STDOUT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define WHITESPACE_DELIMITERS " \t\r\n\a"


/* Used standard libraries included. */
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>



/* System library headers used included. */
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>


/* Struct for built-in functions included. */
#include "structure.h"


/* Character functions prototypes included. */
int _atoi(char *s);
int _isalpha(int c);
int int_length(int n);
int _putchar(char c);
char *_itoa(unsigned int n);


/* Single-string functions prototypes included. */
int _strlen(char *s);
void _puts(char *str);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *des, char *src);


/* Multiple-string functions prototypes included. */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *tok);
char *_strncpy(char *dest, char *src, int n);
int _strncmp(const char *s1, const char *s2, size_t n);


/* Array functions prototypes included. */
void reverse_the_array(char *arr, int a_length);
void *fill_the_array(void *arr, int a_element, unsigned int a_length);


/* Memory functions prototypes included. */
void free_enviro(char **env);
void *allocate_to_array(unsigned int size);
void free_all_pointers(char **input, char *line);
char *memory_copy(char *dest, char *src, unsigned int n);
void *re_allocate(void *ptr, unsigned int old_size, unsigned int new_size);


/* Prompting functions prototypes included. */
void display_the_prompt(void);
char *own_getline(void);
void handle_control_c(int r_signal);
unsigned int check_delimiter_characters(char c, const char *str);


/* Command parsing functions prototypes included. */
int search_path(char **line);
char **parse_the_command(char *cmd);
int execute_the_command(char **tokens, char *line, int count, char **argv);


/* Environment functions prototypes included. */
char *get_enviro_value(char *name);
void create_enviro_array(char **envi);
int enviro(char **cmd, int er);


/* Path and supporting functions prototypes included. */
int check_for_builtins(char **cmd);
char *construct_path(char *token, char *value);
int handle_builtin_command(char **cmd, int er);


/* File handling functions prototypes included. */
void extract_command_from_file(char *filename, char **argv);
void process_file_and_exit(char **tokenized_cmd, char *f_line, FILE *filename);
void execute_file_commands(char *f_line, int count, FILE *f_name, char **argv);


/* Built-in functions prototypes included. */
void handle_hash_character(char *user_input);
int handle_cd_command(char **cmd, int error_no);
int handle_echo_command(char **cmd, int er);
void handle_exit_command(char **cmd, char *user_input, char **argv, int c);


/* Built-in display functions prototypes included. */
int print_echo(char **cmd);
int display_help(char **cmd, int error_status);


/* Built-in history functions prototypes included. */
int history_file(char *user_input);
int show_history(char **cmd, int er);


/* Printing functions prototypes included. */
void print_unsigned_number(unsigned int n);
void print_signed_number(int n);
void display_error(char *line, int c, char **argv);
void print_error(char **argv, int c, char **cmd);


#endif

