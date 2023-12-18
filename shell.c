#include "main.h"



/** Function to execute the command */
int execute_command(char **command, char *path, char **directories);

int main(int argc, char **argv)
{
	char *command = NULL;
	size_t bufsize = MAX_COMMAND_LENGTH;

	if (argc != 1)
	{
		perror("Number of arguments is incorrect");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			perror("Not a terminal");
			exit(EXIT_FAILURE);
		}

		printf("#cisfun$ ");
		fflush(stdout);

		if (getline(&command, &bufsize, stdin) == -1)
			break;

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
			break;

		char **commandArray = malloc(2 * sizeof(char *));
		commandArray[0] = command;
		commandArray[1] = NULL;

		char *path = NULL;
		char **directories = malloc(2 * sizeof(char *));
		directories[0] = "/bin";
		directories[1] = NULL;

		if (execute_command(commandArray, path, directories) != 0)
		{
			perror("Command execution failed");
		}

		free(commandArray);
		free(directories);
	}
	free(command);
	return (0);
}

