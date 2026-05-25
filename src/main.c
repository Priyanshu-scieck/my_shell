#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_shell_parser.h"
#include "my_shell_executor.h"

#define BUFFER_SIZE 1024

void shell_read_loop(void);
bool shell_read_line(char *, int);

int main(void)
{
	shell_read_loop();

	return 0;
}

void shell_read_loop(void)
{
	char input[BUFFER_SIZE];
	char **args;
	int status = 1;

	while (status) {	
		fputs("myshell> ", stdout);
		fflush(stdout);
		
		if (shell_read_line(input, sizeof(input)) == false)
			break;	

		args = shell_parse_line(input);
		if (args == NULL)
			puts("parsing error");
		else
			status = shell_execute(args);

		free(args);
	}
}

bool shell_read_line(char *input, int size)
{
	if (fgets(input, size, stdin) == NULL)
		return false;

	/* removes '\n' in input with '\0' using standard func */
	input[strcspn(input, "\n")] = '\0';

	return true;
}
