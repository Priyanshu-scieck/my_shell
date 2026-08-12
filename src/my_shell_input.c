#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "my_shell_input.h"

bool shell_read_line(char *input, int size)
{
	if (fgets(input, size, stdin) == NULL)
		return false;

	/* removes '\n' in input with '\0' using standard func */
	input[strcspn(input, "\n")] = '\0';

	return true;
}
