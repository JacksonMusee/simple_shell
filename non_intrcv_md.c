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
	char *token = NULL;

	while (getline(&ln_buf, &len, stdin) != -1)
	{
		ln_buf[strcspn(ln_buf, "\n")] = '\0';

		token = strtok(ln_buf, " \t");
		argv[0] = token;

		while (token)
		{
			execute(token, argv, env);
			token = strtok(NULL, " \t");
		}

		free(ln_buf);
	}
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}

	return;
}
