#include "shell.h"
/**
 * handle_input - queries that the input has | it calls the func to handle it
 * if it doesn't have it call handle command function
 * @input: the line input being searched for
 * @envp: enviromantal variable
 * Return: void
*/
void handle_input(char *input, char *envp[])
{
	if (my_substr(input, "|"))
	{
		run_shell(input, envp);
	}
	else
	{
		handle_command(input, envp);
	}
}
