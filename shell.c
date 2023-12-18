#include "main.h"

/**
 * main - main function for shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
	char *command = NULL;
	int status = 0;
	size_t bufsize = MAX_COMMAND_LENGTH;
	pid_t pid;

	(void)argv;

	if (argc != 1)
	{
		perror("Number of arguments is incorrect");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/*issaty: check if stdin come from an actif terminal*/
		if (isatty(STDIN_FILENO) == 0)
		{
			perror("Not a terminal");
			exit(EXIT_FAILURE);
		}

		printf("#cisnotfun$ ");
		fflush(stdout);

		/*getline*/
		if (getline(&command, &bufsize, stdin) == -1)
			break;

		/*if command have ' ' or tabulation*/
		while (command[0] == ' ' || command[0] == '\t')
			command++;
		if (command[0] == '\n' || command[0] == '\0')
			continue;

		command[strcspn(command, "\n")] = '\0';

		/*Exit : compare 2 strings*/
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/*execute the command*/
			argv = tokenize(command);
			execute_command(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/*wait for the child process to terminate*/
			wait(&status);
		}
	}
	free(command);
	return (0);
}
