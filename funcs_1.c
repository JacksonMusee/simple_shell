#include "main.h"

/**
 *fndcmd - Looks for the program name
 *
 *@ln_buf: Ponter to the entered line
 *
 *Return: Ponter to the command
 */

char *fndcmd(char *ln_buf)
{
	char *ln_buf_cp = strdup(ln_buf);
	char *cmd = strtok(ln_buf_cp, " ");

	while(cmd)
	{
		if(strspn(cmd, "./") != 2)
			break;

		cmd = strtok(NULL, " ");
	}

	return (cmd);
}

/**
 *
 *
 *
 */

char **tokenize(char *str)
{
        char *str_cpy = strdup(str);
        char *token;
        int tkn_count;
        char **tkn_arr;
        int i;
	char *delims = " ";

        token = strtok(str_cpy, delims);
        if (token == NULL)
                exit(EXIT_FAILURE);

        tkn_count = 1;
        while (token != NULL)
        {
                tkn_count++;
                token = strtok(NULL, delims);
        }
        str_cpy = strdup(str);

        tkn_arr = malloc(sizeof(tkn_arr) * (tkn_count + 1));
        if (tkn_arr == NULL)
                exit (EXIT_FAILURE);

        i = 0;
        token = strtok(str_cpy, delims);
        while (token != NULL)
        {
                tkn_arr[i] = token;
                i++;
                token = strtok(NULL, delims);
        }
        tkn_arr[i] = NULL;

        return (tkn_arr);
}

/**
 *
 *
 *
 *
 *
 *
 */

char *read_line()
{
	char *ln_buf = NULL;
	size_t len = 0;
	
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

	return (ln_buf);
}
