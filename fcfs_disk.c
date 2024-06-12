#include<stdio.h>
void main()
{
	int requests[100],i,j,n,initialpos,totalheadmoment = 0;
	printf("Enter the Number of Requests : ");
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
    	printf("\nEnter Request [%d] Position : ",i);
    	scanf("%d",&requests[i]);
	}
	printf("\nEnter Initial Head Position : ");
	scanf("%d",&initialpos);
	for(i = 0;i < n;i++)
    {
        totalheadmoment = totalheadmoment + abs(requests[i] - initialpos);
        initialpos = requests[i];
    }    
    printf("\nTotal Head Moment is : = %d",totalheadmoment);
}

