#include<stdio.h>
void main()
{
	int a[50],n,key,i,j;
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
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 &&a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
			}
printf("\nthe array after sorting is..\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
    } 
}
	
