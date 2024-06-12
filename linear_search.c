#include<stdio.h>
void main()
{
	int a[50],n,temp,i,se;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the element to be searched..\n");
	scanf("%d",&se);
	for(i=0;i<n;i++)
	{
	   if(a[i]==se)
	   {
	   	printf("search element found  at loaction %d",i);
	   	temp=1;
	   	break;
	   }
	}
	if(temp==0)
	{
		printf("search element not found..\n");
	}
}
