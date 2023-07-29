#include "shell.h"
/**
 * main - begins the program
 * @argc: the number of arguments used in the program
 * @argv: an array of arguments used in the porgram
 * @envp: an array of environmental variables in the prgm
 * Return: Exit SUCCESS
 **/
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		char *u_input_line;
		size_t input_size_line = 0;
		ssize_t char_read;

		while (1)
		{
			printf("$ ");
			u_input_line = NULL;
			char_read = read_input(&u_input_line, &input_size_line);

			if (char_read < 0)
			{
				perror("read)input");
				free(u_input_line);
				continue;
			}
			if (*u_input_line != '\n')
			{
				handle_input(u_input_line, envp);
			}
			free(u_input_line);
		}
	}
	else
	{
		handle_non_terminal_input();
	}

	exit(EXIT_SUCCESS);
}
