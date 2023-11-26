#include<stdio.h>
#include<conio.h>
int linear(int a[], int key,int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		if(a[i]==key)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int a[20],n,i,key;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the data:");
	for(i=0;i<=n-1;i++)
	scanf("%d",&a[i]);
	printf("enter the elements you want to search:");
	scanf("%d",&key);
	i=linear(a,key,n);
	if(i==-1)
	printf("Not Found");
	else
	printf("%d Found at %d pos",key,i+1);
	getch();
}
