#include<stdio.h>
void main()
{
	int i,n,a[10],se,low,high,mid,found=0;
	printf("enter the size of array\n");
	scanf("%d",&n);
	if(n>10)
	{
		printf("array overflow\n");
	}
	else
	{
	printf("enter elements \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the serach element\n");
	scanf("%d",&se);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==se)
		{
			printf("elemnet found at mid position %d",mid);
			found=1;
			break;
		}
		else if(se<a[mid])
		{
			high=mid-1;
		}
		else if(se>a[mid])
		{
			low=mid+1;
		}
	}
	if(found==0)
	{
		printf("element not found");
	}
}
}
