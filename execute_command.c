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
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (command[0] == '/' || command[0] == '.')
		path = command;
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
		free(path);
		free(argument);
		exit(EXIT_FAILURE);
	}
	free(path);
	free(argument);
	return (1);
}
