#include <stdio.h>
#include "my_shell_builtins.h"

int myshell_help(char **args)
{
    (void)args;

    puts("myshell - a minimal shell written in C\n");
    puts("Built-in commands:");
    puts("  cd [dir]   change directory (supports ~, -, ~/path)");
    puts("  pwd        print current working directory");
    puts("  print      print arguments to stdout (-n to skip newline)");
    puts("  help       show this message");
    puts("  exit       exit the shell");
    puts("\nAny other command is run as an external program via execvp.");

    return 1;
}
