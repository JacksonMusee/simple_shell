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
	size_t len = 0;

	while (getline(&ln_buf, &len, stdin) != -1)
	{
		ln_buf[strcspn(ln_buf, "\n")] = '\0';

		argv[0] = strtok(ln_buf, " \t");

		while (argv[0])
		{
			execute(argv[0], argv, env);
			argv[0] = strtok(NULL, " \t");
		}

		free(ln_buf);
	}
}
