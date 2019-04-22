#include<stdio.h>
#include<conio.h>
int q1c,q2c,q3c;
int roundrobin(int a, int b);
int fcfs(int a, int b);
int priority(int a , int b);
int waiting_time[20];
int main()
{
	printf("\nEnter number of processes in queue 1\t\t::");
	scanf("%d",&q1c);
	printf("\nEnter number of processes in queue 2\t\t::");
	scanf("%d",&q2c);
	printf("\nEnter number of processes in queue 3\t\t::");
	scanf("%d",&q3c);
	int p1,p2,p3;
	char name[3];
	printf("\nEnter priority of queue 1\t\t::");
	scanf("%d",&p1);
	while(1)
	{
	printf("\nEnter priority of queue 2\t\t::");
	scanf("%d",&p2);
	if(p1!=p2)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("\nEnter priority of queue 3\t\t::");
	scanf("%d",&p3);
	printf("____________________________________________________________________________________________________________________\n\n");
	if(p1!=p3&&p2!=p3)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)
	{
		roundrobin(q1c,1);
		if(p2<p3)
		{
			priority(q2c,2);
			fcfs(q3c,3);
		}
		else
		{
			priority(q3c,3);
			fcfs(q2c,2);
		}
	}
	else if(p2<p1&&p2<p3)
	{
		roundrobin(q2c,2);
		if(p1<p3)
		{
			priority(q1c,1);
			fcfs(q3c,3);
		}
		else
		{
			priority(q3c,3);
			fcfs(q1c,1);
		}
	}
	else
	{
		roundrobin(q3c,3);
		if(p1<p2)
		{
			priority(q1c,1);
			fcfs(q2c,2);
		}
		else
		{
			priority(q2c,2);
			fcfs(q1c,1);
		}
	}
	
}
int priority(int a,int b)
{
	int burst_time[20], process[20], turnaround_time[20], priority[20];
      int i, j, limit, sum = 0, position, temp;
      float average_wait_time, average_turnaround_time;
      printf("applying priority scheduling algorithm on queue no. %d",b);
      limit=a;
      int ask=1;
      printf("\nEnter Burst Time and Priority For %d Processes\n", limit);
      if(ask=1)
      {
      	for(i = 0; i < limit; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Burst Time:\t");
            scanf("%d", &burst_time[i]);
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      ask=0;
	  }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = burst_time[i];
            burst_time[i] = burst_time[position];
            burst_time[position] = temp;
            temp = process[i];
      }
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];
            }
            sum = sum + waiting_time[i];
      }
      average_wait_time = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            sum = sum + turnaround_time[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
      }
      average_turnaround_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);
       printf("\n____________________________________________________________________________________________________________________\n\n");
      return 0;
}

int fcfs(int c, int d)
{
	float burst_time[30], waiting_time[30], turnaround_time[30];
        float average_waiting_time = 0.0, average_turnaround_time = 0.0;
        int count, j, total_process;
        printf("applying fcfs on queue no . %d",d);
        total_process=c;
        printf("\nEnter The Burst Time of Processes:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("Process [%d]:", count + 1);
                scanf("%f", &burst_time[count]);
        }
        waiting_time[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + burst_time[j];
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                turnaround_time[count] = burst_time[count] + waiting_time[count];
                average_waiting_time = average_waiting_time + waiting_time[count];
                average_turnaround_time = average_turnaround_time + turnaround_time[count];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, burst_time[count], waiting_time[count], turnaround_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;
        average_turnaround_time = average_turnaround_time / count;
        printf("\nAverage Waiting Time = %f", average_waiting_time);
        printf("\nAverage Turnaround Time = %f", average_turnaround_time);
        printf("\n");
         printf("____________________________________________________________________________________________________________________\n\n");
        return 0;
}

int roundrobin(int e, int f)
{
	int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("applying roundrobin on queue no. %d ",f);
  
	  limit=e; 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
       printf("\n____________________________________________________________________________________________________________________\n\n");
      return 0; 
}
