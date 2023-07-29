#include "shell.h"
/**
 * handle_error - this handles all errors of the pipeline func
 * @message: the error message displayed
 * Return: void
**/
void handle_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}
/**
 * close_pipes - exits from the pipes
 * @pipefd: a file that describes the pipe
 * @num_pipes: represents the  number of pipes
 * Return: void
**/
void close_pipes(int pipefd[][2], int num_pipes)
{
	int i;

	for (i = 0; i < num_pipes; i++)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
	}
}
/**
 * wait_for_children - handle that waits for child proccess
 * @num_commands: receives the number of commands
 * Return: void
**/
void wait_for_children(int num_commands)
{
	int i;

	for (i = 0; i < num_commands; i++)
	{
		wait(NULL);
	}
}
