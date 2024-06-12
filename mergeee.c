#include<stdio.h>
void mergesort(int a[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergesort(a,first,mid);
		mergesort(a,mid+1,last);
		merge(a,first,mid,last);
	}
}
void merge(int a[],int first,int mid,int last)
{
	int b[10],i,j,k;
	i=first;
	j=mid+1;
	k=first;
	while(i<=mid &&j<=last)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k++;
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=last)
		{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			k++;
			i++;
		}
	}
	for(k=first;k<=last;k++)
	{
		a[k]=b[k];
	}
}
void main()
{
	int i,n,a[10];
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
	printf("\nthe elements after sorting..\n");
	mergesort(a,0,n-1);
     for(i=0;i<n;i++)
     printf("%4d",a[i]);
}
}
