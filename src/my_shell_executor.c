#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my_shell_executor.h"

int shell_execute(char **args)
{
	pid_t pid;

	if (args[0] == NULL)
		return 1;

	pid = fork();
	if (pid < 0) {
		/* failed */
		perror("myshell");
	} else if (pid == 0) {
		/* child process */
		execvp(args[0], args);

		perror("myshell");
		exit(EXIT_FAILURE);
	} else {
		/* parent process */
		int status;
		waitpid(pid, &status, 0);
	}

	return 1;
}
