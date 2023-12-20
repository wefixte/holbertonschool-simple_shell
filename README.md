# <p align="center">A Simple Shell </p>
  
----------

**Simple replication of the command-line interpreter Shell. All files are written in C language.**
    
----------


## Overview:

The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.  It is the program that is running when a user logs into the system (although a user can select a different shell with the chsh(1) command). The shell implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities. dash(1) - Linux man page


----------


## Compilation:

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


----------


## Ressources:

- [Everything you need to know to start coding your own shell ](https://intranet.hbtn.io/concepts)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
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

## Libraries:

[stdarg.h ](https://en.wikipedia.org/wiki/Stdarg.h) | [unistd.h](https://en.wikipedia.org/wiki/Unistd.h) | [sys/wait.h](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/wait.h.html) | [stdlib.h](https://es.wikipedia.org/wiki/Stdlib.h) | [sys/stat.h](https://pubs.opengroup.org/onlinepubs/007908799/xsh/sysstat.h.html)

----------

## Files:

| File | Description 
| -------- | -------- |
| main.h   | Libraries, declarations.    |
| Row 2    | Search and init built-ins  |
| Row 3    | Create and execute processes  | 
| Row 4    | Free memory  | 
| Row 5    | Get environment variables |
| Row 6    | Count arguments and breaks them into tokens |
| Shell.c    | Main Function |

----------

## Flowcharts:

![](https://example.com/your-image.png)

----------

## Authors:

Cassandre Pernelle | Github

Abdelmalek M'hamed | Github 

Holberton School - Foundations - Low-level programming & Algorithm  Linux and Unix system programming.

Decembre, 2023, France

