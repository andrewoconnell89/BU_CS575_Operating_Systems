/*
 CS575 Operating Systems
 Implement my own shell
 Andy OConnell
 2017-02-16
 */

//Header files needed 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>

//Define constants
#define MAXLINE 1024
#define MAXARGS 20
#define PROMPT "myshell> "
#define HISTSIZE 10 //history size


int main(int argc, char *argv[])
{
  
  // you will need a while/for loop to repeatedly 
  // do the following things:

  // print the prompt using printf()/fprintf()
  
  // get a commandline from the console
  // using fgets()
  
  // parse the command by calling the following 
  // parse function parseCmd()

  // handle the special command such as exit ...
  
  // otherwise, fork a child using fork()
  
  // execute the command in the child process 
  // using execvp()

  // wait child process to finish in the parent process 
  // using wait()/waitpid() (if the child process is not 
  // a background job )

  // check the fork/exec/wait example we show in the class.
  // use command "man" to check how to use the library functions 
  // or system call mentioned above

  return 0;
}

/* 
 * parsecmd - Parse the command line and build the argv array.
 * Return the number of arguments.
 *
 * The command is parsed through the delimiter space " ". 
 * You may need to modify this function to support background job & symbol,
 * and input/output redirect symbol <, > | 
 * Be aware that there may no space between these symbols and 
 * other parts of the command e.g. ls>lsout, emacs&
 */
int parsecmd(const char *cmdline, char *arglist[]) 
{
  static char array[MAXLINE]; /* holds local copy of command line */
  char *buf = array;          /* ptr that traverses command line */
  char *delim;                /* points to first space delimiter */
  int argc;                   /* number of args */
  int bg;                     /* background job? */
  
  strncpy(buf, cmdline, strlen(cmdline)+1);
  buf[strlen(buf)-1] = ' ';  /* replace trailing '\n' with space */
  while (*buf && (*buf == ' ')) /* ignore leading spaces */
    buf++;
  
  /* Build the arglist list */
  argc = 0;
  // based on delimiter " "(space), separate the commandline into arglist
  while ((delim = strchr(buf, ' ')) && (argc < MAXARGS - 1)) {
    arglist[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' ')) /* ignore spaces */
      buf++;
  }
  arglist[argc] = NULL;
  return argc;
  
}


/*
To compile this file, in any terminal, type:
gcc myshell.c -o mysh
This will generate an executable file mysh. To start your shell, type:
./mysh
Currently, nothing will output because it hasn't been implement. 
 */
