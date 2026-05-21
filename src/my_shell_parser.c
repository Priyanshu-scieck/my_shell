#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_shell_parser.h"

static inline bool isDelim(const char);
static char *getTok(char *);


char **shell_parse_line(char *line)
{
	char **args = malloc(ARGS_LEN * sizeof(char *));

	if (args == NULL) {
		return NULL;
	}

	int i = 0;
	char *str = getTok(line);

	while (str != NULL && i < ARGS_LEN - 1) {
		args[i++] = str;
		str = getTok(NULL);
	}
	args[i] = NULL;

	return args;
}

static inline bool isDelim(const char ch)
{

	for (int i = 0; TOKEN_DELIMETER[i] != '\0'; i++) {
		if (ch == TOKEN_DELIMETER[i])
			return true;
	}

	return false;

}

static char *getTok(char *line)
{
	static char *tokpos = NULL;

	if (line != NULL) {
		tokpos = line;
	}

	if (tokpos == NULL) {
		return tokpos;
	}

	char *tok_start = tokpos;

	while (*tokpos != '\0') {

		if (isDelim(*tokpos)) {

			// checking for empty string
			if (tokpos == tok_start) {
				tokpos++;
				tok_start++;
			} else {
				break;
			}

		} else {
			tokpos++;
		}

	}	

	// checking if end reached and deciding return string
	if (*tokpos != '\0') {
		*tokpos = '\0';
		tokpos++;
	} else if (tokpos == tok_start){
		tok_start = NULL;
	}

	return tok_start;

}
