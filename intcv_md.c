#include "main.h"

/**
 *
 *
 *
 *
 *
 */

void intrcv_main(char **argv, char **env)
{
	char *ln_buf = NULL;

	while (1)
	{
		printf("($) ");

		ln_buf = read_line();
		ln_buf[strcspn(ln_buf, "\n")] = '\0';

		argv[0] = strdup(ln_buf);

		if (strcmp(argv[0], "exit") == 0)
		{
			free(ln_buf);
			free(argv[0]);
                        _exit(EXIT_SUCCESS);
		}

		execute(argv[0], argv, env);

		free(ln_buf);
		free(argv[0]);
	}

}
