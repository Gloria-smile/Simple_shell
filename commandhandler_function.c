#include "shell.h"
/**
 * handle_command - checks for the command
 * if it  a-a  built-in- function
 * OR b- has a file in the dir /bin/, OR 3- has a path
 * @command: recieves and edits line inputs from user
 * @envp:the environmental variable[] used
 * Return:an integer value
*/
int handle_command(char *command, char *envp[])
{
	char **final_string;
	int buildin_containter, value_chpt_func, status;
	char *value_chfile;

	final_string = string_tokenization(command);

	if (final_string[0] == NULL || final_string[0][0] == '\0')
	{
		free(final_string);
		return (0);
	}
	if (my_strcmp("exit", final_string[0]) == 0)
		my_exit(final_string);

	buildin_containter = check_build_in_func(final_string[0], envp);
	value_chfile = file_check(final_string[0]);

	if (buildin_containter == 0 && value_chfile != NULL)
		final_string[0] = value_chfile;

	value_chpt_func = path_check_function(final_string[0]);
		if (value_chpt_func == 1)
		{
			status = fork_execute_function(final_string, envp);
			free(value_chfile);
			free(final_string);
			return (status);
		}

	if (value_chfile == NULL && value_chpt_func == 0 && buildin_containter == 0)
	{
		printf("%s: No such file or directory\n", final_string[0]);
	}
	free(value_chfile);
	free(final_string);
	return (127);
}
