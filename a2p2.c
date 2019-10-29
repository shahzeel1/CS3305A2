#include <stdio.h>
#include <string.h>

int main()
{

FILE *fp, *fo;
char buff[255];

fp = fopen("cpu_scheduling_input_file.txt", "r");
if(fp==NULL)
{
	printf("File does not exist");
	return 0;
}

int *queue;
//int *sjfqueue;
//int *pqueue;
//int *wqueue;
int numq=0;
int nump=0;
int tq;
int ptime;
int sum=0;
float avg;


// until the end of the file is reached...
printf("%d",feof(fp));
while (feof(fp)==0)
{
	fscanf(fp,"%s", buff);
	printf("%s",buff);
	if (strcmp(buff,"q"))// if new queue is starting get the time quantum and store the processes in an array
	{
	   numq++;// increment the queue number 
	   fscanf(fp,"%s", buff);// skip over the q val
	   fscanf(fp,"%s", buff); // skip over the tq chars
	   fscanf(fp,"%s", buff); // get the tq val
	   sscanf(buff, "%d", &tq);// store the  time quantum 
	   fscanf(fp,"%s", buff);// read the first process
	   while (!strcmp(buff,"\n"))
	   {
		   sscanf(buff, "%d", &ptime);// store the process time as an int
		   *queue = ptime;// store the process time in the queue
		   nump ++;
		   queue ++;// increment the memory location in the queue
		   fscanf(fp,"%s", buff);// read the next process
		}
		
		// open file to write to 
		fo = fopen( "cpu_scheduling_output_file.txt", "w+" );
		fprintf(fo,"Ready Queue 1 Applying FCFS Scheduling: \n");
		printf("Ready Queue 1 Applying FCFS Scheduling: \n");
		fprintf(fo,"Order of selection by CPU: \n");
		printf("Order of selection by CPU: \n");		
		
		// FCFS Algorithm 
		int i;
		for(i=1; i<=nump; i++)
		{
			printf("here");
			fprintf(fo,"p%d, ",i);
			printf("p%d, ",i);
		}
		queue = queue-nump;
		fprintf(fo,"\n\nIndividual waiting time for each process \n");
		printf("\n\nIndividual waiting time for each process \n");
		fprintf(fo,"p%d = %d\n",1,0);
		printf("p%d = %d\n",1,0);
		for(int i=2; i <= nump; i++)
		{
			sum+=*queue;
			fprintf(fo,"p%d = %d\n",i,sum);
			printf("p%d = %d\n",i, sum);
			queue++;
		}	
		
		avg = sum/nump;
		fprintf(fo,"\n\nAverage waiting time for each process: %f\n",avg);
		printf("\n\nAverage waiting time for each process: %f\n",avg);
		/*
		//SJF Alogrithm
		queue=queue-nump; // reset queue 
		sjfqueue=queue;// equate the two queues 
		// set up the process queue
		for(int i=1, i<=nump; i++)
		{
			*pqueue=i;
			pqueue++;
		}
		wqueue=pqueue;
		wqueue=wqueue-nump;
		 
		// do a quick sort and change the values of the processes as well 
		
		quicksort (sjfqueue, wqueue, 0,nump-1);
		
		fprintf(fo,"Ready Queue 1 Applying SJF Scheduling: \n");
		printf(fo,"Ready Queue 1 Applying SJF Scheduling: \n");
		sum=0;
		pqueue=pqueue-nump;
		sjfqueue=sjfqueue-nump;
		for(int i=1, i<=nump; i++)
		{
			
			fprintf(fo,"p%d = %d\n",*wqueue,sum);
			printf(fo,"p%d = %d\n",*wqueue, sum);
			sum+=*sjfqueue;
			wqueue++;
			sjfqueue++;
		}	
		
		avg = sum/pnum;
		fprintf(fo,"\n\nAverage waiting time for each process: %d\n",avg);
		printf(fo,"\n\nAverage waiting time for each process: %d\n",avg);
		
		fprintf(fo,"Ready Queue 1 Applying RR Scheduling: \n");
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
	}
}

fclose(fp);
fclose(fo);
			
		
	return 0;	

		
		
			
	}
	
	/*quicksort(sjfq[], pq[], min, max)
	{
		int split;
		int part;
		int lowest;
		int temp;
		
		if (min<max)
		{
			
			split = sjfq[max];
			lowest = (min-1);
			
			for (int j=min; j<=max-1; j++)
			{
				if(sjdq[j]<split)
				{
					lowest++;
					temp=sfjq[lowest];
					sfjq[lowest]=sfjq[j];
					sfjq[j] = temp;
					
					temp=pq[lowest];
					pq[lowest]=pq[j];
					pq[j] = temp;
					
				}
			}
					temp=sfjq[lowest+1];
					sfjq[lowest+1]=sfjq[max];
					sfjq[max] = temp;
					
					temp=pq[lowest+1];
					pq[lowest+1]=pq[max];
					pq[max] = temp;
					
					part = lowest+1;
			quicksort(sjfq, pq, min, part-1);
			quicksort(sjfq, pq, min+1, part);
		}
	}
		
	*/	
		
		
	
		
		
		
		
		
		
	
		
		   
	   
	   
	  
