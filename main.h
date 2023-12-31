#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char *ln_buf, char **argv, char **env);
char *fndcmd(char *ln_buf);
char **tokenize(char *str);
void intrcv_main(char **argv, char **env);
void non_intrcv(char **argv, char **env);
void exec_cmd_args(int argc, char **argv, char **env);
char *read_line();

#endif
