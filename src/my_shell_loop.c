#include <stdio.h>
#include <stdlib.h>
#include "my_shell_input.h"
#include "my_shell_utils.h"
#include "my_shell_parser.h"
#include "my_shell_executor.h"
#include "my_shell_loop.h"

void shell_read_loop(void)
{
	char input[BUFFER_SIZE];
	char **args;
	int status = 1;

	while (status) {	
		print_prompt();
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
