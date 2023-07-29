#include "shell.h"
/**
 * my_exit - it exits the program
 * @argument:this represents an array of arguments
 * Return: nothing
 **/
void my_exit(char **argument)
{
	int my_stat = 0, a;

	if (argument[1] != NULL)
	{
		my_stat = my_atoi(argument[1]);
	}
	for (a = 0; argument[a] != NULL; a++)
	{
		free(argument[a]);
	}
	free(argument);
	exit(my_stat);
}
