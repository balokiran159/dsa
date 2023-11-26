#include<stdio.h>
#include<conio.h>
void bubble(int a[],int n)
{
	int i,j,temp;
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
}
int main()
{
	int a[20],i,n,temp;
	printf("Enter The renge:");
	scanf("%d",&n);
	printf("Enter the data:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a,n);
	printf("shorted list is:");
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
}
