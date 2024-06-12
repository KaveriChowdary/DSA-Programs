#include<stdio.h>
void main()
{
	int i,n,a[10],j,swap;
	printf("enter the size of array\n");
	scanf("%d",&n);
	if(n>10)
	{
		printf("array overflow\n");
	}
	else{
	printf("enter elements \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("the elements before sorting\n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
	//logic on bubble sort...
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
			  swap=a[j];
			  a[j]=a[j+1];
			  a[j+1]=swap;	
			}
		}
	}
     printf("\nthe elements after sorting..\n");
     for(i=0;i<n;i++)
     printf("%4d",a[i]);
}
}

