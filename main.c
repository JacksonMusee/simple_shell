#include "main.h"

/**
 *main - entry point
 *
 *@argc: Number of command line arguments
 *@argv: Array of command line arguments
 *@env: Array of environment variable
 *
 *Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *ln_buf = NULL;
	size_t len = 0;

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

		execute(ln_buf, argv, env);
	}

	free(ln_buf);

	return (0);
}

/**
 *execute - Execute a parsed command in a child process
 *
 *@ln_buf: Pointer to the command
 *@argv: Array of command line arguments
 *@env: Array of environment variables
 *
 */
void execute(char *ln_buf, char **argv, char **env)
{
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			if (strlen(ln_buf) == 0)
				exit(EXIT_SUCCESS);

			if (execve(argv[0], argv, env))
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
}
