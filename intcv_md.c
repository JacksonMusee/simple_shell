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

		printf("%s\n", ln_buf);

		if (strlen(ln_buf) == 0)
		{
			free(ln_buf);
			continue;
		}

		argv[0] = strtok(ln_buf, " ");

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

		free(ln_buf);
	}

}
