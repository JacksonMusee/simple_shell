#include "main.h"

/**
 *
 *
 *
 *
 */

void non_intrcv(char **argv, char **env)
{
	char *ln_buf = NULL;
	char *cl_ln_buf = NULL;
	int i = 0;
	int j = 0;

	ln_buf = read_line();
	cl_ln_buf = malloc(sizeof(ln_buf));

	while (ln_buf[i] != '\0')
	{
		if (ln_buf[i] != ' ' && ln_buf[i] != '\t' && ln_buf[i] != '\n')
		{
			cl_ln_buf[j] = ln_buf[i];
			i++;
			j++;
		}
		else
		{
			if (cl_ln_buf[j - 1] != ' ' && cl_ln_buf[j - 1] != '\t' && cl_ln_buf[j - 1] != '\n')
			{
				cl_ln_buf[j] = ' ';
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

	}
	cl_ln_buf[j+1] = '\0';

	argv[0] = strtok(cl_ln_buf, " ");

	while (argv[0])
	{
		execute(argv[0], argv, env);
		argv[0] = strtok(NULL, " ");
	}

	free(cl_ln_buf);
	free(ln_buf);
}
