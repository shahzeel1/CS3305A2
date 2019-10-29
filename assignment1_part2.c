#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
 
  if (argc!=3)
  {
	  printf("Incorrect arguments\n");
	  exit(0);
  }
  const char* X;
  char Y[512]; 	
  int Xint,Yint;
  int fd[2];
  pid_t pid,parent,child;
 
  if (pipe(fd) < 0){
    perror("pipe error");
    exit(0);
  }
   parent = getpid();
   printf("\nA pipe id created for  communication between parent (PID %d) and child \n", parent);
   
  pid = fork();
  if (pid < 0) {
    perror("fork error");
    exit(0);
  }

  if(pid > 0) //parent
  {
    
    parent = getpid();
    X = argv[1];
    printf("\nparent (PID %d) Reading X = %s from the user\n",parent, X);
    wait(NULL);
    read (fd[0],Y,512);
    printf("\nparent (PID %d) Reading Y from the pipe (Y= %s)\n",parent, Y);
    Xint = atoi(X);
    Yint = atoi(Y);
    printf("\nparent (PID %d) adding X + Y = %d\n",parent, (Xint+Yint));
    
    
  
  } else //child
   
  {
    child = getpid();
    parent = getppid();
    printf("\nparent (PID %d) created a child (PID %d)\n", parent, child);
    printf("\nchild (PID %d) Reading Y = %s from the user", child, argv[2]);
    printf("\nchild (PID %d) Writing Y into the pipe",child);
    write(fd[1],argv[2],strlen(argv[2]));
   }

  return 0;

}
