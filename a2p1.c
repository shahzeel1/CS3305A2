#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

  

int sum =0;

void *thread_calc(void *num) 
{ 
    int *val = (int*) num;
    
    sum += *val;
    
    return 0; 
} 
   

int main() 
{ 
	int x = 10;
	int y=20;
	int z = 0;
	pid_t pid;
	
	
    pthread_t thread_1,thread_2; 
    
    
    pid=fork();

	if (pid<0)
		{ 
			printf("fork unsuccessful");
			exit(1);
		}

	if(pid> 0) // parent 
	{
		wait(NULL);
		printf("\nThe value of z in child is %d",z);
		pthread_create(&thread_1, NULL, thread_calc, &x);
		pthread_create(&thread_2, NULL, thread_calc, &y); 
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL); 
    wait(NULL);
    z=sum;
    
    printf("\nThe value of z in parent is %d",z);
    
	}

    if (pid ==0)
    {
		z = x+y;
		printf("\nChild finished calc");
	}
return 0; 

}
