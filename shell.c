#include "main.h"

/**
 * main - main function for shell
 * Return: 0 on success
*/

int main(void)
{
	char *command = NULL;
	char **argv;
	int status = 0;
	pid_t pid;

	while (1)
	{
		command = read_command();
		if (command == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		while (command[0] == ' ' || command[0] == '\t')
			command++;
		if (command[0] == '\n' || command[0] == '\0')
			continue;

		if (strcmp(command, "exit") == 0) /*Exit : compare 2 strings*/
			exit(EXIT_SUCCESS);

		pid = fork(); /*create a new process*/
		if (pid == -1) /*if fork failed*/
			perror("Error");
		else if (pid == 0) /*Child process*/
		{
			/*execute the command*/
			argv = tokenize(command);
			execute_command(argv[0]);
			exit(EXIT_SUCCESS);
		}
		else /*Parent process*/
			wait(&status);
	}
	free(command);
	return (0);
}
