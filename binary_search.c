#include<stdio.h>
void main()
{
	int a[50],n,found=0,i,se,low,high,mid;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the element to be searched..\n");
	scanf("%d",&se);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(se==a[mid])
		{
			printf("element found at mid position %d",mid);
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
		printf("element not found..\n");
	}n
	}
