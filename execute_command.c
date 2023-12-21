#include "main.h"
/**
 * execute_command - Function to execute the command
 * @command: Pointer to array of strings representing the command to executed
 * Return: 1 if successfull
 */

int execute_command(char *command)
{
	char **argument, *path;
	int index;

	argument = tokenize(command);

	if (argument == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (command[0] == '/' || command[0] == '.')
		path = strdup(command);
	else
		path = getpath(argument[0]);
	if (path == NULL)
	{
		free(argument);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (execve(path, argument, environ) == -1)
	{
		perror("Error");
		for (index = 0; argument[index] != NULL; index++)
			free(argument[index]);
		free(path);
		free(argument);
		free(command);
		exit(EXIT_FAILURE);
	}
	free(path);
	free(argument);
	return (1);
}
