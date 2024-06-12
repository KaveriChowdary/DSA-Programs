#include<stdio.h>
void main()
{
	int i,n,a[10],j,key;
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
	printf("the elements before sorting\n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
	//logic on insertion sort..
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	 printf("\nthe elements after sorting..\n");
     for(i=0;i<n;i++)
     printf("%4d",a[i]);
}
}

