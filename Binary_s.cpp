//Binary Search
#include<stdio.h>
#include<conio.h>
int binary(int a[], int key, int n)
{
	int mid,low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key>a[mid])
		{
			low=mid+1;
		}
		else if(key<a[mid])
		{
			high=mid-1;
		}
		else 
		{
			return mid;
		}
		
	}
	return -1;
}
int main()
{
	int a[50],n,i,key;
	printf("Enter the Renge: ");
	scanf("%d",&n);
	printf("Enters the Data: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter The element you want to Search: ");
	scanf("%d",&key);
	i= binary(a,key,n);
	if(i==-1)
	printf("Data not found");
	else
	printf("%d found at %d position",key,i+1);
}
