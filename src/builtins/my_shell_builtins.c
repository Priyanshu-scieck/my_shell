#include <string.h>
#include "my_shell_builtins.h"

struct builtin {
	char *cmd;
	int (*func)(char **);
};

static struct builtin builtins[] = {
	{"exit", myshell_exit},
	{"cd", myshell_cd},
	{"help", myshell_help},
	{"pwd", myshell_pwd},
	{"print", myshell_print}
};

int handle_builtin(char **args, int *executed)
{
	int built_size = sizeof(builtins) / sizeof(builtins[0]);
	*executed = 0;

	for (int i = 0; i < built_size; i++) {
		if (strcmp(args[0], builtins[i].cmd) == 0) {
			*executed = 1;
			return builtins[i].func(args);
		}
	}

	return 1;
}
