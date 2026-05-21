#include <stdlib.h>
#include <string.h>
#include "my_shell_parser.h"


char **shell_parse_line(char *line)
{
	char **args = malloc(ARGS_LEN * sizeof(char *));

	if (args == NULL) {
		return NULL;
	}

	int i = 0;
	char *str = strtok(line, TOKEN_DELIMETER); 	// used standard string.h func

	while (str != NULL && i < ARGS_LEN - 1) {
		args[i++] = str;
		str = strtok(NULL, TOKEN_DELIMETER);
	}
	args[i] = NULL;

	return args;
}
