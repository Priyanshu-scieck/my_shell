#ifndef MY_SHELL_BUILTINS_H
#define MY_SHELL_BUILTINS_H

int handle_builtin(char **, int *);
int myshell_cd(char **);
int myshell_pwd(char **);
int myshell_exit(char **);
int myshell_help(char **);
int myshell_print(char **);

#endif
