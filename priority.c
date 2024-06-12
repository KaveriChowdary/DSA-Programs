#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char p[10][15],temp2[10][15];
	int tot=0,wt[10],i,n,pt[10],pr[10],turn[10],totturn=0;
	float avg,avgturn;
	printf("Enter no. of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the process%dname\n",i+1);
		scanf("%s",&p[i]);
		printf("Enter process time\n");
		scanf("%d",&pt[i]);
		printf("enter the priority\n");
		scanf("%d",&pr[i]);
	}
	
		int temp,temp1,j;
   for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(pr[j]>pr[j+1])
			{
				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
   			temp1=pt[j];
   			pt[j]=pt[j+1];
   			pt[j+1]=temp1;
   			strcpy(temp2[i],p[j]);
	    strcpy(p[j],p[j+1]);
	    strcpy(p[j+1],temp2[i]);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+pt[i-1];
		tot=tot+wt[i];
	}
	avg=(float)tot/n;
	for(i=0;i<n;i++)
	{
		turn[i]=pt[i]+wt[i];
		totturn=totturn+turn[i];
	}
	avgturn=(float)totturn/n;
	printf("P_name\tP_time\tpriority_time\tw_time\tturn_time\n");
	
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t\t%d\t%d\t%d\n",p[i],pt[i],pr[i],wt[i],turn[i]);
	  
	}
	printf("Total waiting time=%d\n avg time=%f\n turn time=%d\n avg turn time=%f\n",tot,avg,totturn,avgturn);

	
}
