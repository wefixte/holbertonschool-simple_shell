#include "main.h"

/**
 * execute_command - Function to execute the command
 * @command: Pointer to an array of strings representing the command to be executed
 * @path: Pointer to a string representing the path to the command executable
 * @directories: Pointer to an array of strings representing additional directories
 *   to search for the command executable
 * Return: Exit status of the executed command (0 if successful)
 */
int execute_command(char **command, char *path, char **directories)
{
	int status;
	/** Create a child process using the fork() system call */
	int child_pid = fork();

	/** Check if the fork() call failed */
	if (child_pid == -1)
	{
		/** Print an error message using perror() and return -1 */
		perror("fork");
		return (-1);
	}

	/** If the child process was created successfully */
	else if (child_pid == 0) {

		/** Check if the specified path is NULL */
		if (path == NULL) {
			/** Concatenate the command path from the directories array */
			char *concat_path = malloc(strlen(directories[0]) + strlen(command[0]) + 2);
			strcpy(concat_path, directories[0]); /** Copy the first directory */
			strcat(concat_path, "/"); /** Append a '/' separator */
			strcat(concat_path, command[0]); /** Append the command name */

			/** Replace the command path with the concatenated path*/
			command[0] = concat_path;

			/** Execute the command using the execve() system call*/
			execve(command[0], command, environ); // Pass the command array and environment pointer

			/** If execve() failed, print an error message and free the allocated memory*/
			perror("execve");
			free(concat_path);
			free(command);
			exit(EXIT_FAILURE); /** Exit the child process with failure status */
		}

		/** Otherwise, use the specified path directly */
		else
		{
			execve(path, command, environ);

			/** If execve() failed, print an error message and free the allocated memory */
			perror("execve");
			free(command);
			exit(EXIT_FAILURE);
		}
	}

	/** If this is the parent process, wait for the child process to finish */
	else
	{
		wait(&status); /** Wait for the child process to exit and store its status in 'status'*/
	}

	/** Return the exit status of the child process*/
	return WEXITSTATUS(status);
}
