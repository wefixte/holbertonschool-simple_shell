#include "main.h"
/**
* tokenize - Tokenize a string
* @input: The string to tokenize
* Return: A pointer to an array of strings
*/
char **tokenize(char *input)
{
	char *token;
	char **args = NULL;
	int argCount = 0;

	/* Allocate memory for arguments */
	args = malloc(sizeof(char *));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \t\n"); /* Tokenize input using delimiters*/

	while (token != NULL)
	{
		args[argCount] = strdup(token); /* Copy each token to args */
		if (args[argCount] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		argCount++;
		token = strtok(NULL, " \t\n"); /* Get next token */
		/*Reallocate memory for next element*/
		args = realloc(args, (argCount + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
	}
	/* Set last element of args to NULL */
	args[argCount] = NULL;
	if (argCount == 0) /*Free memory if no argument find*/
	{
		free(args);
		return (NULL);
	}
	return (args);
}
