#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute(char *ln_buf, char **argv, char **env);
char *fndcmd(char *ln_buf);

#endif