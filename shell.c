#include "main.h"

/**
 * main - main function for shell
 * Return: 0 on success
*/

int main(void)
{
	char *command = NULL, *command_start = NULL;
	int status = 0;
	pid_t pid;

	while (1)
	{
		command = read_command();
		command_start = command;
		if (command == NULL)
		{
			printf("\n");
			free(command_start);
			exit(EXIT_SUCCESS);
		}

		while (command[0] == ' ' || command[0] == '\t')
			command++;
		if (command[0] == '\n' || command[0] == '\0')
		{
			free(command_start);
			continue;
		}

		if (strcmp(command, "exit") == 0)
		{
			free(command_start);
			exit(EXIT_SUCCESS);
		}

		pid = fork(); /*create a new process*/

		if (pid == -1)
		{
			free(command);
			perror("Error");
		}

		else if (pid == 0) /*Child process*/
		{
			/*execute the command*/
			execute_command(command);
			free(command_start);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
			free(command_start);
		}
	}
	return (0);
}
