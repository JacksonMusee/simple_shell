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

		argv[0] = strtok(ln_buf, " ");

		if (argv[0] == NULL)
			continue;

		if (strcmp(argv[0], "exit") == 0)
		{
			free(ln_buf);
                        _exit(EXIT_SUCCESS);
		}

		while (argv[0])
		{
			execute(argv[0], argv, env);
			argv[0] = strtok(NULL, " ");
		}

		free(argv[0]);
		free(ln_buf);
	}

}
