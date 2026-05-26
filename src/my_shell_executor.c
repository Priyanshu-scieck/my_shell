#include <stdio.h>
#include "my_shell_executor.h"
#include "my_shell_builtins.h"
#include "my_shell_external.h"

int shell_execute(char **args)
{
	int is_builtin;
	int status;

	if (args[0] == NULL)
		return 1;

	/* handles internal commands */
	status = handle_builtin(args, &is_builtin);
	if (is_builtin)
		return status;

	/* handles external commands */
	return handle_external(args);
}
