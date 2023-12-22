#include "main.h"

/**
 * getpath - get the full path of a command
 * @input: command enter by the user
 * Return: returns the full path if found in the PATH
 * OR returns the command if not found
*/

char *getpath(char *input)
{
	char *path, *token, *copypath, *entirepath = NULL;
	int length;

	path = getenv("PATH"); /*search for environment strings*/
	if (path == NULL || strlen(path) == 0)
		return (strdup(input));

	copypath = strdup(path); /*Return a pointer to a new string duplicate*/
	token = strtok(path, ":"); /*breaks string into a series of tokens*/

	/*loop through the string to get the full path*/
	while (token != NULL)
	{
		/*Allocate memory for the entire path*/
		length = strlen(token) + strlen(input) + 2; /*+2 for the / & the null*/
		entirepath = malloc(sizeof(char) * (length + 1)); /*+1 for the null byte*/

		if (entirepath == NULL) /*if malloc fails*/
		{
			free(copypath);
			perror("Error in memory allocation");
			exit(EXIT_FAILURE);
		}

		/*copy the path and the command into the entire path*/
		strcpy(entirepath, token);
		strcat(entirepath, "/");
		strcat(entirepath, input);

		/*Checks whether the calling process can access the file pathname*/
		if (access(entirepath, F_OK | X_OK) == 0)
		{
			free(copypath);
			return (entirepath);
		}
		free(entirepath);
		token = strtok(NULL, ":"); /*returns a pointer to the next token*/
	}
	free(copypath);
	return (strdup(input)); /*Return a pointer to a new string duplicate*/
}
