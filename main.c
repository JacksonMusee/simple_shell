#include "main.h"

/**
 *
 *
 *
 *
 */

extern char **environ;

int main(int argc, char *argv[])
{
	char *ln_buf = NULL;
	size_t len = 0;
	pid_t child_pid;
	
	(void)argc;

	while (1)
	{
		printf("($) ");

		if (getline(&ln_buf, &len, stdin) == -1)
		{
			free(ln_buf);
			perror("Error: Getline() failed");
			exit(EXIT_FAILURE);
		}

		ln_buf[strcspn(ln_buf, "\n")] = '\0';
		argv[0] = ln_buf;
		
		if (strcmp(argv[0], "exit") == 0)
			_exit(EXIT_SUCCESS);

		child_pid = fork();
		if (child_pid == 0)
		{
			if (strlen(ln_buf) == 0)
				exit(EXIT_SUCCESS);

			if (execve(argv[0], argv, environ))
			{
				free(ln_buf);
				perror("Error: execve() failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}

		free(ln_buf);
		len = 0;
	}
}
