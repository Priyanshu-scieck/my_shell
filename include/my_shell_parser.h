// can use #pragma once
#ifndef MY_SHELL_PARSER_H
#define MY_SHELL_PARSER_H

#define TOKEN_DELIMETER " \t\n\r\a"
#define ARGS_LEN 64

char **shell_parse_line(char *line);

#endif
