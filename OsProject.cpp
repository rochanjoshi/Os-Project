#include<stdio.h>

struct process
{
      char name;
      int arr_time, br_time, comp_time, wait_time, turn_ar_time, priority;  
      int status;
}queue[10];

int n; 
void SortArrivalTime() 
{
      struct process temp;
      int a, b;
      for(a = 0; a < n - 1; a++)
      {
            for(b = a + 1; b < n; b++)
            {
                  if(queue[a].arr_time > queue[b].arr_time)
                  {
                        temp = queue[a];
                        queue[a] = queue[b];
                        queue[b] = temp;
                  }
            }
      }
}

int main()
{
      int l, time = 0, btime = 0, largest; 
      char c; 
      float wtime = 0, tatime = 0, avg_wt, avg_tat;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &n); 
      for(l = 0, c = 'A'; l < n; l++, c++)
      {
            queue[l].name = c;  
            printf("\nEnter Details For Process[%c]:\n", queue[l].name); 
            printf("Enter Arrival Time:\t"); 
            scanf("%d", &queue[l].arr_time ); 
            printf("Enter Burst Time:\t"); 
            scanf("%d", &queue[l].br_time); 
            printf("Enter Priority:\t"); 
            scanf("%d", &queue[l].priority); 
            queue[l].status = 0; 
            btime = btime + queue[l].br_time; 
      }
      SortArrivalTime();
      queue[9].priority = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time = queue[0].arr_time; time < btime;)
      {
            largest = 9;
            for(l = 0; l < n; l++)
            {
                  if(queue[l].arr_time <= time && queue[l].status != 1 && queue[l].priority > queue[largest].priority)
                  {
                        largest = l;
                  }
            }
            time = time + queue[largest].br_time;
            queue[largest].comp_time = time;
            queue[largest].wait_time = queue[largest].comp_time - queue[largest].arr_time -queue[largest].br_time; 
            queue[largest].turn_ar_time = queue[largest].comp_time - queue[largest].arr_time; 
            queue[largest].status = 1; 
            wtime = wtime + queue[largest].wait_time; 
            tatime = tatime + queue[largest].turn_ar_time;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",queue[largest].name,queue[largest].arr_time,queue[largest].br_time,queue[largest].priority,queue[largest].wait_time);
      }
      avg_wt = wtime/n; 
      avg_tat = tatime/n; 
      printf("\n\nAverage waiting time:\t%f\n", avg_wt); 
      printf("Average Turnaround Time:\t%f\n", avg_tat); 
}
