#include "shell.h"
/**
 * wait_for_my_child - this waits for the child proccess to exit
 * @my_child: the pid of the child proccess
 * Return: notifies on error, exit status SUCCESS
 **/
int wait_for_my_child(pid_t my_child)
{
	int wstatus;

	if (waitpid(my_child, &wstatus, 0) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(wstatus))
	{
		return (WEXITSTATUS(wstatus));
	}
	else if (WIFSIGNALED(wstatus))
	{
		fprintf(stderr, "Error with child proccess\n");
		exit(EXIT_FAILURE);
	}
	return (-1);
}
