#include "main.h"

/**
 * execute_command - Function to execute the command
 * @command: Pointer to array of strings representing the command to executed
 * Return: 1 if successfull
 */

int execute_command(char *command)
{
	char **argument, *path;

	argument = tokenize(command);

	if (argument == NULL)
	{
		free(argument);
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (command[0] == '/' || command[0] == '.')
	{
		path = strdup(command);
	}
	else
	{
		path = getpath(command);
	}

	if (path == NULL)
	{
		free(path);
		free(argument);
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (execve(command, argument, environ) == -1)
	{
		free(path);
		free(argument);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (1);
}
