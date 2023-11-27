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
	char **cmd;
	int i = 0;
	char *ln_buf = NULL;
	size_t len = 0;
	int is_terminal;
	(void)argc;

	is_terminal = isatty(fileno(stdin));
	while (1)
	{
		if (is_terminal)
			printf("($) ");

		if (getline(&ln_buf, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				free(ln_buf);
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(ln_buf);
				perror("Error: Getline() failed");
				exit(EXIT_FAILURE);
			}
		}

		if (is_terminal)
		{
			ln_buf[strcspn(ln_buf, "\n")] = '\0';
		}
		else
		{
			ln_buf[strlen(ln_buf) - 1] = '\0';
		}
		argv[0] = ln_buf;

		if (strcmp(argv[0], "exit") == 0)
			_exit(EXIT_SUCCESS);

		if (execute(argv[0], argv, env) == -1)
		{

			cmd = tokenize(argv[0]);

			while(cmd[i])
			{
				argv[0] = cmd[i];
				execute(argv[0], argv, env);
				i++;
			}
		}
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
int execute(char *ln_buf, char **argv, char **env)
{
		pid_t child_pid = fork();

		if (child_pid == 0)
		{
			if (strlen(ln_buf) == 0)
				exit(EXIT_SUCCESS);

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
