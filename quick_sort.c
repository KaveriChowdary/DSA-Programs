#include<stdio.h>
void quicksort(int a[],int first,int last)
{
	int i,j,pivot,temp,n;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot] &&i<last)
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,0,j-1);
		quicksort(a,j+1,last);
	}
}
int main()
{
	int a[50],n,i;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("the array before sorting\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
	quicksort(a,0,n-1);
	printf("\nthe array after sorting\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);	
	return 0;
}
