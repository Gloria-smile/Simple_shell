#include "shell.h"
/**
 * create_pipe - function that creates the pipe
 * @pipefd: a storage container for the fd of |
 * @num_pipes: displays the numbers of | tp creates
 * Return: if we did it =>0 on success,if not =>1 on failure
 */
int create_pipes(int pipefd[][2], int num_pipes)
{
	int i;

	for (i = 0; i < num_pipes; i++)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("pipe");
			return (1);
		}
	}
	return (0);
}
/**
 * free_commands - it empty the memory
 * @commands: an array of commands
 * @num_commands: displays the amount of commands
 * Return: void
 */
void free_commands(char *commands[], int num_commands)
{
	int i;

	for (i = 0; i < num_commands; i++)
	{
		free(commands[i]);
	}
}
/**
 * my_pipline_handler - pipline  cmd handler.
 * @pipeline:string of pipline  cmds
 * @envp: env var array
 * Return: 0 on success, 1 on failure
 */
int my_pipline_handler(char *pipeline, char *envp[])
{
	return (run_shell(pipeline, envp));
}
