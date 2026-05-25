#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my_shell_external.h"

int handle_external(char **args)
{

	pid_t pid;

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
		int wait_status;
		waitpid(pid, &wait_status, 0);
	}

	return 1;
}
