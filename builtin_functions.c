#include "shell.h"
/**
 * my_env - an environmental value is printed through it
 * Return: return 0 success
 */
int my_env(void);
/**
 * check_build_in_func - this checks the string builtin function
 * @final_string: receives input from users
 * @envp: this is an array of environmental variables
 * Return: it  returns an integer value
 */
int check_build_in_func(char *final_string, char *envp[])
{
	char *array_buitin[] = {"cd", "exit", "env"};
	int num_builtins = sizeof(array_buitin) / sizeof(array_buitin[0]);
	int f;
	(void)envp;

	for (f = 0; f < num_builtins; f++)
	{
	if (my_strcmp(array_buitin[f], final_string) == 0)
	{
		switch (f + 1)
		{
		case 1:
			chdir(final_string);
			return (1);

		case 2:
			exit(EXIT_SUCCESS);

		case 3:
			my_env();
			return (1);

		default:
			return (0);
		}
	}
	}

	return (0);
}
