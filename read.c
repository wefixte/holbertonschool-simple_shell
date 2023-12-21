#include "main.h"

/**
 * read_command - read command from stdin and return it
 * Return: command on success, NULL on failure
*/

char *read_command(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t read;

	/*issaty: check if stdin come from an actif terminal*/
		if (isatty(STDIN_FILENO))
			printf("#cisnotfun$ ");

		fflush(stdout); /*flushes the output buffer of a stream*/

		/*getline() reads an entire line from stream and store the adress of the buffer containing the text*/
		read = getline(&command, &size, stdin);
		if (read == -1)
		{
			free(command);
			return (NULL);
		}
		command[read - 1] = '\0'; /*replace the new line with a null byte*/
		return (command);
}
