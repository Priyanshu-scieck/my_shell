#include "my_shell_builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int myshell_cd(char **args)
{
	char *tar = args[1];
	if (!args[1] || strncmp(args[1], "~", 2) == 0)
       		tar = getenv("HOME");

	if (!tar) {
		fputs("myshell: cd: HOME not set\n", stderr);
		return 1;
	}

	if (chdir(tar) < 0)
		fprintf(stderr, "myshell: cd: %s: %s\n", tar, strerror(errno));

	return 1;
}
