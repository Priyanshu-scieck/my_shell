#include "my_shell_builtins.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int myshell_cd(char **args)
{
	char *tar = args[1];
	char *alloc_path = NULL;
	
	// home dir using 'cd' or 'cd ~'
	if (!args[1] || strcmp(args[1], "~") == 0) {
       		tar = getenv("HOME");
		if (!tar || *tar == '\0') {
			fputs("myshell: cd: HOME not set\n", stderr);
			return 1;
		}
	} 
	// prev directory using 'cd -'
	else if (strcmp(args[1], "-") == 0) {
		tar = getenv("OLDPWD");
		if (!tar || *tar == '\0') {
			fputs("myshell: cd: OLDPWD not set\n", stderr);
			return 1;
		}
		puts(tar);
	} 
	// resolving path 'cd ~/path'
	else if (args[1][0] == '~' && args[1][1] == '/') {
		char *home = getenv("HOME");
		if (!home || *home == '\0') {
			fputs("myshell: cd: HOME not set\n", stderr);
			return 1;
		}

		int len = strlen(home) + strlen(&args[1][1]) + 1;
		alloc_path = malloc(len * sizeof(*alloc_path));
		if (!alloc_path) {
			perror("myshell: cd: malloc");
			return 1;
		}

		snprintf(alloc_path, len, "%s%s", home, &args[1][1]);
		tar = alloc_path;
	}

	if (chdir(tar) < 0) {
		fprintf(stderr, "myshell: cd: %s: %s\n", tar, strerror(errno));
	} else {
		char *old = getenv("PWD");
		if (old)
			setenv("OLDPWD", old, 1);

		char *cwd = getcwd(NULL, 0);
		if (cwd) {
			setenv("PWD", cwd, 1);
			free(cwd);
		}
	}

	free(alloc_path);
	return 1;
}
