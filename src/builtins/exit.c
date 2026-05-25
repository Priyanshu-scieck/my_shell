#include <stdio.h>
#include "my_shell_builtins.h"

int myshell_exit(char **args)
{
	(void)args;

	puts("exiting shell.....");
	puts("exited");

	return 0;
}
