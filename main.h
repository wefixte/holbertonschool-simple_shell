#ifndef MAIN_H
#define MAIN_H

/*Librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*Environment variable*/
extern char **environ;

/*Maximum length command*/
#define MAX_COMMAND_LENGTH 100

/*Prototypes*/
int main(int argc, char **argv);

#endif
