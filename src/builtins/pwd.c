#include "my_shell_builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int myshell_pwd(char **args)
{
	(void)args;

	const char *pwd = getenv("PWD");
	if (pwd) {
		puts(pwd);
		return 1;
	}

	char *cwd = getcwd(NULL, 0);
	if (!cwd) {
		perror("myshell: pwd");
		return 1;
	}

	puts(cwd);
	free(cwd);
	return 1;
}
