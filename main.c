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
	int is_terminal;
	(void)argc;

	is_terminal = isatty(fileno(stdin));

	if (is_terminal == 1)
		intrcv_main(argv, env);

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
int execute(char *ln_buf, char **argv, char **env)
{
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			if (strlen(ln_buf) == 0)
			{
				free(argv[0]);
				free(ln_buf);
				exit(EXIT_SUCCESS);
			}

			if (execve(argv[0], argv, env) == -1)
			{
				return (-1);

			}
		}
		else
		{
			wait(NULL);
		}

	return (0);
}
