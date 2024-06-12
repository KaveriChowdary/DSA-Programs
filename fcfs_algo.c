#include<stdio.h>
#include<stdlib.h>
main()
{
	char p[10][15];
	int tot=0,wt[10],i,n,pt[10],turn[10],totturn=0;
	float avgwt=0,avgturn=0;
	printf("enter the no.of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter process %d name:",i+1);
		scanf("%s",&p[i]);
		printf("enter the process time \n");
		scanf("%d",&pt[i]);
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+pt[i-1];
		tot=tot+wt[i];
	}
	avgwt=(float)tot/n;
	for(i=0;i<n;i++)
	{
		turn[i]=pt[i]+wt[i];
		totturn=totturn+turn[i];
	}
	avgturn=(float)totturn/n;
	printf("p_name \t p_time \t w_time\t turn_time\t\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\n",p[i],pt[i],wt[i],turn[i]);
	  
	}
	printf("Total waiting time=%d\n avg time=%f\n turn time=%d\n avg turn time=%f\n",tot,avgwt,totturn,avgturn);	
}

