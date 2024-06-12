//program on merge sort....
#include<stdio.h>
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		//sorting 1st and 2nd subarrays
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high)
{
	int i=low, j=mid+1,k=low, b[50];
	while(i<=mid &&j<=high)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		//copying the remaining elements of a[j]
		while(j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		//copying the remaining elements of a[i]
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}	
}
void printArray(int a[], int n)
{
int i;
for (i=0; i <n; i++)
printf("%4d ", a[i]);
}
int main()
{
	int a[50],n,i;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("the array before sorting..\n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
	mergesort(a,0,n-1);
	printf("\nthe array after sorting..\n");
	printArray(a,n);
}

