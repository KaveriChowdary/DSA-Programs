#include<stdio.h>
main()
{
	char p[10][15];
	int tot=0,bt[10],i,n,turn[10],totturn=0,wt[10],tq,totwt=0,st[10],temp,sq=0,count=0;
	float avg=0,avgturn=0;
	printf("Enter no. of process\n");
	scanf("%d",&n);
	printf("enter time quantum value\n");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		printf("Enter the process %d name\n",i+1);
		scanf("%s",&p[i]);
		printf("Enter burst time\n");
		scanf("%d",&bt[i]);	
		st[i]=bt[i];
    } 
   while(1)
   { 
   	for(i=0,count=0;i<n;i++)
   	{
   		temp=tq;
   		if(st[i]==0)
   		 {
   		 	count++;
   		 	continue;
		 }
		 if(st[i]>tq)
			{
			st[i]=st[i]-tq;
		    }
		    else
           {
		   if(st[i]>=0)
			{
				temp=st[i];
				st[i]=0;
			}
	       }
			sq=sq+temp;
			turn[i]=sq;
	}
		if(count==n)
	   break; 
   }   1      
   for(i=0;i<n;i++)
   {
   		totturn=totturn+turn[i];
   }
   for(i=0;i<n;i++)
   {
   	wt[i]=turn[i]-bt[i];
   	totwt=totwt+wt[i];
   }
   avgturn=(float)totturn/n;
   avg=(float)totwt/n;
   printf("P_name\tburst_time\twait_time\tturn_time\n");
	
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t\t\t%d\t\t%d\n",p[i],bt[i],wt[i],turn[i]);
	  
	}
	printf("Total waiting time=%d\n avg time=%f\n turn time=%d\n avg turn time=%f\n",totwt,avg,totturn,avgturn);	
}
   
   
