#include<stdio.h>
#include<stdlib.h>
main()
{
	char p[10][15];
	int tot=0,at[10],i,n,bt[10],turn[10],totturn=0,wt[10],ct[10],totwt=0;
	float avg=0,avgturn=0;
	printf("Enter no. of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
		printf("Enter the process%dname\n",i);
		scanf("%s",&p[i]);
		printf("Enter arrival time\n");
		scanf("%d",&at[i]);
		printf("Enter bus time\n");
		scanf("%d",&bt[i]);
        }
    ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=bt[i]+ct[i-1];
	}
	for(i=0;i<n;i++)
	{
		turn[i]=ct[i]-at[i];
		totturn=totturn+turn[i];
	}
		avgturn=(float)totturn/n;
	for(i=0;i<n;i++)
	{
	  wt[i]=turn[i]-bt[i];
        totwt=totwt+wt[i];
    }
	avg=(float)totwt/n;
	printf("P_name\tarrival_time\tbus_time\tcompletion_time\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t\t\t%d\t\t%d\n",p[i],at[i],bt[i],ct[i]);
	  
	}
	printf("Total waiting time=%d\n avg time=%f\n turn time=%d\n avg turn time=%f\n",totwt,avg,totturn,avgturn);	
}
