# Simple Shell Project

This project is a simple UNIX command line interpreter implemented in C as part of a pair programming effort for the ALX Software Engineering program. It aims to replicate basic functionalities of the Unix shell (sh). The shell supports executing commands and handling basic interactions.

## Project Requirements

The project was done in accordance with some strict requirements including but not limited to:

- Compilation: Ubuntu 20.04 LTS, using gcc with flags -Wall -Werror -Wextra -pedantic -std=gnu89.
- Memory Management: Code should be free from memory leaks.
- Error Output: Error messages should match the format and behavior of /bin/sh.

## Compilation

To compile the shell, use:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

The shell can be used in interactive mode or non-interactive mode as follows:

### Interactive Mode:
Run the executable in your terminal after compiling:
```bash
ubuntu@ubuntu:~/simple_shell$ ./hsh
($) /bin/ls
file1.c file2.c file3.c
($) exit
ubuntu@ubuntu:~/simple_shell$
```

### Non-Interactive Mode
Run the executable in your terminal after compiling:
```bash
ubuntu@ubuntu:~/simple_shell$ echo "/bin/ls" | ./hsh
file1.c file2.c file3.c
ubuntu@ubuntu:~/simple_shell$
```


## Supported Commands

The shell supports the execution of basic commands. It handles:

- Single-word commands
- Commands with arguments
- PATH resolution
- Built-in commands: `exit` (to exit the shell) and `env` (to print the environment)

## Authors

This project was developed by [Tapiwanashe Mlambo](https://github.com/tapiwamla) and [Tatenda Torerwa](https://github.com/TatendaTorerwa) for the [ALX Software Engineering Program](https://www.alxafrica.com/software-engineering-plus/) Program. _See [AUTHORS](AUTHORS)_.
