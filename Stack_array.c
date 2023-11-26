#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int stack_arr[MAX];
int push();
int pop();
int display();
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.DISPLAY");
		printf("\n4.QUIT");
		printf("\nEnter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(1);
					break;	
			default : printf("wrong choice");							
		}
		
	}
}
int push()
{
	int push_item;
	if(top==MAX-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		printf("Enter the item:");
		scanf("%d",&push_item);
		top=top+1;
		stack_arr[top]=push_item;
	}
}
int  pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Poped item is %d:\n",stack_arr[top]);
		top=top-1;
	}
}
int display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Stack element is:");
		for(i=top;i>=0;i--)
		printf("%d",stack_arr[i]);
	}
}


