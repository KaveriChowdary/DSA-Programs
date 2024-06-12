#include<stdio.h>
void main()
{
	int a[50],n,min,swap,i,j;
	printf("enter the size\n");
	scanf("%d",&n);
	if(n>50)
	{
		printf("array overflow\n");
	}
	else
	{
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("the array before sorting is...\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
	//..logic on insertion sort
	for(i=0;i<n-1;i++)
	{
		//...finding min element
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		//,,,swapping the found min element
		if(min!=i)
		{
			swap=a[i];
			a[i]=a[min];
			a[min]=swap;
		}
	}
		printf("\nthe array after sorting is..\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
}
	
	}
