# <p align="center">A Simple Shell </p>
  


![Image](https://cdn.discordapp.com/attachments/1186717231644676196/1187405115787837450/1P1FKnYJTJxW87fe71611dg.png?ex=6596c430&is=65844f30&hm=b791d691a79e19aec01928817e6075b0dae8d7bbecf20f847133832c26b45c95&)
        
----------

**Simple replication of the command-line interpreter Shell. All files are written in C language.**
    
----------


## Overview:

The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.  It is the program that is running when a user logs into the system (although a user can select a different shell with the chsh(1) command). The shell implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities. dash(1) - Linux man page


----------

## Requirements:

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to [why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)

----------


## Compilation:
Created and tested with Ubuntu 14.04 LTS

Compiled with GCC 4.8.4 with flags: -Wall -Werror -Wextra -pedantic -std=gnu89

Code files must be compiled this way:

`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`


----------
## Builtin Functions:


| Command |  Description | 
| -------- | -------- |
| env  | display the environmental variables |
|  exit    | exit the shell |
        

## Usage:

The Simple Shell should work like this in interactive mode (simple commands can be typed directly to the running shell):

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

And also in non-interactive mode (commands can be put into a file and the file can be executed directly):

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Exiting the shell 
When you want to exit the shell, you can use one of the following methods:

1: Type the command "exit"

`exit`

2: Press on Ctrl + D

`2: Press on Ctrl + D`

----------

## Ressources:

- [Everything you need to know to start coding your own shell ](https://intranet.hbtn.io/concepts)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
----------

## Libraries:

[stdarg.h ](https://en.wikipedia.org/wiki/Stdarg.h) | [unistd.h](https://en.wikipedia.org/wiki/Unistd.h) | [sys/wait.h](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/wait.h.html) | [stdlib.h](https://es.wikipedia.org/wiki/Stdlib.h) | [sys/stat.h](https://pubs.opengroup.org/onlinepubs/007908799/xsh/sysstat.h.html)

----------

## Files:

| File | Description 
| -------- | -------- |
| main.h   |Header file with function declarations and includes needed for the shell program.    |
| getpath.c | This function gets the path to the executable files from the environment variable PATH. It opens the PATH environment variable and reads the value into a buffer. It then splits the buffer into individual paths, storing them in an array. Finally, it returns the array of paths. |
| execute_command.c  | This function takes a command as input and executes it. It first splits the command into individual arguments using the tokenization function. It then searches for the executable file for the first argument in the array of paths. If the executable file is found, it creates a child process to run the command. The child process will execute the command and then terminate. If the executable file is not found, an error message is printed to the console. | 
| read.c | This function reads a line of input from the user. It first opens the standard input stream (stdin) and reads a character from it. If the character is a newline character, it stops reading and returns the line of input. If the character is not a newline character, it stores it in a buffer and then reads the next character. | 
| tokenization.c | This function takes a string as input and splits it into individual tokens. It first allocates memory for an array of tokens. It then iterates over the string, splitting it into tokens using the whitespace character as a delimiter. Each token is stored in the array of tokens. Finally, it returns the array of tokens.|
| read.c | Count arguments and breaks them into tokens |
| Shell.c    | This is the main function of the shell program. It calls the getpath function to get the path to the executable files. It then enters a loop that repeatedly reads a line of input from the user, splits it into tokens, and executes the command. If the command is the exit command, the loop terminates.|
| AUTHORS | Contains authors' names and github links |
| README.md | File containing information about other files in the same directory.|

----------

## Flowcharts Simple shell:

![](https://i.imgur.com/qRm1mTi.jpeg)

        
----------
## Bugs

No known Bugs.

----------

## Authors:

Cassandre Pernelle | [Github](https://github.com/wefixte/holbertonschool-simple_shell)

Abdelmalek M'hamed | [Github](https://github.com/wefixte/holbertonschool-simple_shell) 

----------
## Licence:

Given the open source nature of the project, no special licenses or license whatsoever is needed to use, modify, and redistribute the simple shell program.

Holberton School - Foundations - Low-level programming & Algorithm  Linux and Unix system programming.

Decembre, 2023, France

