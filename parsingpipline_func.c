#include "shell.h"
/**
 * parse_pipeline_commands - reduces commands into small bits
 * @pipeline: the input line
 * @num_commands: carries the amount of commands
 * Return : an array of commands
**/
char **parse_pipeline_commands(char *pipeline, int *num_commands)
{
	int i = 0;
	char *token = strtok(pipeline, "|");
	char **commands = malloc(MAX_COMMANDS * sizeof(char *));

	if (commands == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		*num_commands = 0;
		return (NULL);
	}
	while (token != NULL && i < MAX_COMMANDS)
	{
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			*num_commands = i;
			free_commands(commands, i);
			return (NULL);
		}
		i++;
		token = strtok(NULL, "|");
	}
	*num_commands = i;
	return (commands);
}
