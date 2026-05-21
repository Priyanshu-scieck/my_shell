#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my_shell_parser.h"

#define BUFFER_SIZE 1024

void shell_read_loop(void);
bool shell_read_line(char *, int);

int main(void)
{

	shell_read_loop();
	
	return 0;
}


void shell_read_loop(void){

	char input[BUFFER_SIZE];

	while (1) {	

		fputs("myshell> ", stdout);
		fflush(stdout);
		

		if (shell_read_line(input, sizeof(input)) == false)
			break;

		if (strncmp(input, "exit", 5) == 0) {
			puts("exiting shell....");
			break;
		}
		
		char **args = shell_parse_line(input);

		if (args == NULL) {
			puts("parsing error");
		}
		else {
			int i = 0;
			while (args[i] != NULL) puts(args[i++]);
		}

		free(args);
	}

	puts("exited");
	
}

bool shell_read_line(char *input, int size) {

	if (fgets(input, size, stdin) == NULL) {
		 return false;
	}

	// newline removal loop
	int i = 0;
	while (input[i] != '\0' && input[i] != '\n') {
		i++;
	}
	input[i] = '\0';

	return true;
}
