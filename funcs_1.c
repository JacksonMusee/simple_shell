#include "main.h"

/**
 *fndcmd - Looks for the program name
 *
 *@ln_buf: Ponter to the entered line
 *
 *Return: Ponter to the command
 */

char *fndcmd(char *ln_buf)
{
	char *ln_buf_cp = strdup(ln_buf);
	char *cmd = strtok(ln_buf_cp, " ");

	while(cmd)
	{
		if(strspn(cmd, "./") != 2)
			break;

		cmd = strtok(NULL, " ");
	}

	return (cmd);
}
