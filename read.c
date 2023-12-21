#include "main.h"

/**
 * read_command - read command from stdin
 * Return: command
*/

char *read_command(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t read;

	/*issaty: check if stdin come from an actif terminal*/
		if (isatty(STDIN_FILENO))
			printf("#cisnotfun$ ");

		fflush(stdout);

		read = getline(&command, &size, stdin);
		if (read == -1)
		{
			free(command);
			return (NULL);
		}
		command[read - 1] = '\0';
		return (command);
}
