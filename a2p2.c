#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int sjfq[], char* pq[], int min, int max);
int main()
{



int *queue = malloc (1000*sizeof(int));
int *sjfqueue = malloc (1000*sizeof(int));
char **pqueue = malloc (1000*sizeof(char*));
char **wqueue = malloc (1000*sizeof(char*));
int numq=0;
int nump=0;
float count=0;
int tq;
//int ptime;
int sum=0;
float avg;
//int queuecounter =0;
char* line = NULL;
size_t lbsize=0;
ssize_t lsize;
char *token;
int filesize;

FILE *fp, *fo;


fp = fopen("cpu_scheduling_input_file.txt", "r");
if(fp==NULL)
{
	printf("File does not exist");
	return 0;
}


// open file to write to 
fo = fopen( "cpu_scheduling_output_file.txt", "w+" );




// until the end of the file is reached 
//while (!feof(fp))
//{
	// get the line for the file 
	lsize=getline(&line, &lbsize, fp); 
	
	token = strtok(line," "); // q
	numq++;// increment the queue number 
	
	
	token = strtok(NULL," "); // skip the q number 
	token = strtok(NULL," ");// skip the tq
	token = strtok(NULL," "); // get the tq value 
	tq = atoi(token); // convert the token to an int val 

	 
	 token = strtok(NULL, " "); // read the first process 
	while (token!=NULL)
	{
    
	pqueue[nump]= token; //  store it in the process queue
	token = strtok(NULL, " "); // read the first process burst time
	queue[nump] = atoi(token);//store the burst time 
	nump++; // increment the number of processes
	count++; 
	token = strtok(NULL, " "); // read the next process
	}
	
	
	   
		  
		
		
		
		fprintf(fo,"Ready Queue 1 Applying FCFS Scheduling: \n");
		printf("Ready Queue 1 Applying FCFS Scheduling: \n");
		fprintf(fo,"Order of selection by CPU: \n");
		printf("Order of selection by CPU: \n");		
		
		// FCFS Algorithm 
		
		for(int i=0; i<nump; i++)
		{
			fprintf(fo,"%s ",pqueue[i]);
			printf("%s ",pqueue[i]);
		}
		
		
		fprintf(fo,"\n\nIndividual waiting time for each process \n");
		printf("\n\nIndividual waiting time for each process \n");
		
		int avgsum=0;
		
		for(int i=0; i < nump; i++)
		{
			fprintf(fo,"%s = %d\n",pqueue[i],sum);
			printf("%s = %d\n",pqueue[i],sum);
			avgsum+=sum;
			sum+=queue[i];
			
			
		}	
		
		avg = avgsum/count;
		fprintf(fo,"\n\nAverage waiting time for each process: %.1f\n",avg);
		printf("\n\nAverage waiting time for each process: %.1f\n",avg);
		
		
		//SJF Alogrithm
		sjfqueue=queue;// equate the two queues 
		wqueue=pqueue;
		 
		// do a quick sort and change the values of the processes as well 
		
		quicksort (sjfqueue, wqueue, 0,nump-1);
		
		fprintf(fo,"\nReady Queue 1 Applying SJF Scheduling: \n");
		printf("\nReady Queue 1 Applying SJF Scheduling: \n");
		
		fprintf(fo,"\nOrder of Selection: \n");
		printf("\nOrder of Selection: \n");
		
		for(int i=0; i<nump; i++)
		{
			fprintf(fo,"%s ",wqueue[i]);
			printf("%s ",wqueue[i]);
		}
		fprintf(fo,"\n\nIndividual waiting time for each process \n");
		printf("\n\nIndividual waiting time for each process \n");
		
		
		sum=0;
		avgsum=0;
		for(int i=0; i<nump; i++)
		{
			
			fprintf(fo,"%s = %d\n",wqueue[i],sum);
			printf("%s = %d\n",wqueue[i], sum);
			avgsum+=sum;
			sum+=sjfqueue[i];
		}	
		
		avg = avgsum/count;
		fprintf(fo,"\n\nAverage waiting time for each process: %.1f\n",avg);
		printf("\n\nAverage waiting time for each process: %.1f\n",avg);
		
	/*	fprintf(fo,"Ready Queue 1 Applying RR Scheduling: \n");
		printf(fo,"Ready Queue 1 Applying RR Scheduling: \n");
		
		
		int index, unfinished, tqtotal = 0, bool = 0,wtime = 0, ttime = 0,;
		int  *tqueue;
		int *processfinqueue;
		int *temp; 
		
		// get the number of processes and set that as the value of unfinished processes
		unfinished = nump;
		temp=queue;
		
		for (int i=0; i<nump; i++)
		{
			
			
		
		}
		
		for(tqtotal=0, index=0; unifinished!=0)
		{
			if(*temp<= tq && *temp>0)
			{
				tqtotal = tqtotal + *temp;
				*temp = 0; 
				bool=1;
			}
			else if (*temp > 0)
			{
				*temp=*temp-tq;
				tqtotal = tqtotal+tq;
			}
			
			if(*temp == 0 && bool ==1)
			{
				unifinished --;
				*tqueue
		*/
	
//}
free(queue);
fclose(fp);
fclose(fo);
			
		
	return 0;	

		
		
			
	}
	
void swap (int* aa, int* ab, char** ba, char** bb)
{
	int tempa= *aa;
			*aa=*ab;
			*ab = tempa;
	char* tempb =*ba;
			*ba=*bb;
			*bb = tempb;
}
int splitter(int sjfq[], char* pq[], int min, int max)
{
	int piv = sjfq[max];
	int i = (min-1);
	
	for (int j = min; j<=max-1;j++)
	{
		if(sjfq[j]<piv)
		{
			i++;
			swap(&sjfq[i],&sjfq[j],&pq[i],&pq[j]);
		}
		
	}
	swap(&sjfq[i+1],&sjfq[max],&pq[i+1],&pq[max]);
	return (i+1);
}
	
			
	
void quicksort(int sjfq[], char* pq[], int min, int max)
	{
		int split;

		
		if (min<max)
		{
			
			split = splitter(sjfq,pq,min,max);
			
			quicksort(sjfq, pq, min, split-1);
			quicksort(sjfq, pq, split+1, max);
		}
	}
		
	
		
		
	
		
		
		
		
		
		
	
		
		   
	   
	   
	  
