#ifndef MAIN_H
#define MAIN_H

/*Librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/*Environment variable*/
extern char **environ;

/*Prototypes*/
int main(void);
int execute_command(char *command);
char **tokenize(char *input);
char *getpath(char *input);
char *read_command(void);

#endif
