#include <stdlib.h>
#include <string.h>
#include "my_shell_parser.h"

char **shell_parse_line(char *line)
{
	char **args = malloc(ARGS_LEN * sizeof(char *));
	char *str;
	int i = 0;

	if (args == NULL)
		return NULL;

	str = strtok(line, TOKEN_DELIMETER);
	while (str != NULL && i < ARGS_LEN - 1) {
		args[i++] = str;
		str = strtok(NULL, TOKEN_DELIMETER);
	}
	args[i] = NULL;

	return args;
}
