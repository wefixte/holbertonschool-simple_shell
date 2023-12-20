#include "main.h"

/**
 * getpath - get the path of the command
 * @input: command enter by the user
 * Return: returns the full path if found in the PATH
 * OR returns the command if not found
*/

char *getpath(char *input)
{
	char *path, *token, *copypath, *entirepath;
	int length;

	path = getenv("PATH");
	if (path == NULL || strlen(path) == 0)
		return (strdup(input));

	copypath = strdup(path);
	token = strtok(path, ":");

	while (token != NULL)
	{
		length = strlen(token) + strlen(input) + 2;
		entirepath = malloc(sizeof(char) * (length + 1));

		if (entirepath == NULL)
		{
			free(copypath);
			perror("Error");
			exit(EXIT_FAILURE);
		}

		entirepath = strcpy(entirepath, token);
		entirepath = strcat(entirepath, "/");
		entirepath = strcat(entirepath, input);

		if (access(entirepath, F_OK | X_OK) == 0)
		{
			free(copypath);
			return (entirepath);
		}
		free(entirepath);
		token = strtok(NULL, ":");
	}
	free(copypath);
	return (strdup(input));
}
