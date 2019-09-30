#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,n,time,rem,f=0,timeI;
	int wait=0,tat=0,at[10],bt[10],rt[10];

	printf("Enter Total Process:\n");
	scanf("%d",&n);
	rem=n;

	for(i=0;i<n;i++)
	{
		printf("Enter Arrival Time and Burst Time For ProcessNo %d:",i+1);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}

	printf("Enter Time Unit Iteration =");
	scanf("%d",&timeI);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	for(time=0,i=0;rem!=0;)
	{
	if(rt[i]<=timeI && rt[i]>0)
	{
		time=time+rt[i];
		rt[i]=0;
		f=1;
	}
	else if(rt[i]>0)
	{
		rt[i]-=timeI;
		time=time+timeI;
	}

	if(rt[i]==0 && f==1)
	{
		rem--;
		printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
		wait=wait+time-at[i]-bt[i];
		tat=tat+time-at[i];
		f=0;
	}

	if(i==n-1)
	{
		i=0;
	}
	else if(at[i+1]<=time)
	{
		i++;
	}
	else
	{
		i=0;
	}
    }

	printf("\nAverage Waiting Time = %f\n",wait*1.0/n);
	printf("Average Turnaround Time(TAT) = %f",tat*1.0/n);

	return 0;
}
//Mayank Soni
