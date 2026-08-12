#include "my_shell_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_prompt(void)
{
	char *cwd = getenv("PWD");
	char *home = getenv("HOME");
	char *alloc_cwd = NULL;

	fputs(GREEN, stdout);
	fputs("myshell", stdout);
	fputs(RESET, stdout);
	fputs(": ", stdout);
	fputs(BLUE, stdout);

	if (!cwd) {
		alloc_cwd = getcwd(NULL, 0);
		cwd = alloc_cwd;
	}

	if (home && *home && cwd) {
		size_t home_len = strlen(home);
		if (strncmp(cwd, home, home_len) == 0 && 
				(cwd[home_len] == '\0' || cwd[home_len] == '/')) {
			fputs("~", stdout);
			fputs(cwd + home_len, stdout);
		} else {
			fputs(cwd, stdout);
		}
	} else if (cwd) {
		fputs(cwd, stdout);
	} else {
		fputs("?", stdout);
	}

	fputs(RESET, stdout);
	fputs(" > ", stdout);
	fflush(stdout);
	
	free(alloc_cwd);
}
