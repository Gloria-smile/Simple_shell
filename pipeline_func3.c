#include "shell.h"
/**
 * execute_commands - where the commands in pipeline is performed
 * @commands: an array of pipeline commands
 * @num_commands: the amount of commands in the pipeline
 * @pipefd: pip fd array
 * @envp: the enviromental variable array
 * Return: void
**/
void execute_commands(char *commands[], int num_commands,
		int pipefd[][2], char *envp[])
{
	int i;

	for (i = 0; i < num_commands; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			handle_error("Failed to create child process.");
			exit(1);
		}
		if (pid == 0)
		{
			if (i == 0)
			{
				dup2(pipefd[i][1], STDOUT_FILENO);
			}
			else if (i == num_commands - 1)
			{
				dup2(pipefd[i - 1][0], STDIN_FILENO);
			}
			else
			{
				dup2(pipefd[i - 1][0], STDIN_FILENO);
				dup2(pipefd[i][1], STDOUT_FILENO);
			}
			close_pipes(pipefd, num_commands - 1);
			exit(handle_command(commands[i], envp));
		}
	}
}
