#include "main.h"

/**
 * main - Entry point of the shell program
 * Return: 0 on success
*/

int main(void)
{
	char *command = NULL, *command_start = NULL;
	int status = 0;
	pid_t pid;

	while (1)
	{
		command = read_command(); /*read the command from the user*/
		command_start = command;
		if (command == NULL)
		{
			free(command_start);
			exit(EXIT_SUCCESS);
		}

		while (command[0] == ' ' || command[0] == '\t') /*skip leading spaces*/
			command++;
		if (command[0] == '\n' || command[0] == '\0') /*if command is empty*/
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
			waitpid(pid, &status, 0); /*wait for a specific PID*/
			if (WIFEXITED(status)) /*if child process terminated normally*/
				status = WEXITSTATUS(status); /*get the exit status of the child process*/
			free(command_start);
		}
	}
	return (0);
}
