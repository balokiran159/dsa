//Selection sort
#include<stdio.h>
#include<conio.h>
void selection(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
int main()
{
	int a[50],i,n;
	printf("Enter the Range:");
	scanf("%d",&n);
	printf("Enters the data:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	selection(a,n);
	printf("Shorted list is:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
