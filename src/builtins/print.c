#include <stdio.h>
#include <string.h>
#include "my_shell_builtins.h"

int myshell_print(char **args)
{
	int start = 1;
	int print_newline = 1;

	if (args[1] && strcmp(args[1], "-n") == 0) {
		print_newline = 0;
		start = 2;
	}

	for (int i = start; args[i]; i++) {
		if (i != start)
			fputs(" ", stdout);
		fputs(args[i], stdout);
	}


	if (print_newline)
		fputs("\n", stdout);
	fflush(stdout);

	return 1;
}
