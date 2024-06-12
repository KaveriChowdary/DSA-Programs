#include<stdio.h>
void main()
{
	int a[50],n,temp,i,j;
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
	//...logic for bubble sort
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nthe array after sorting is..\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
    } 
}
