#include <stdio.h>
#include "my_shell_builtins.h"

int myshell_print(char **args)
{
	for (int i = 1; args[i] != NULL; i++)
		puts(args[i]);

	if (args[1] == 0)
		puts("");

	return 1;
}
