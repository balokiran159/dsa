#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct stack{
	int data;
	struct stack*next;
}Stack;
void push(Stack**p,int n)
{
	Stack*q;
	q=(Stack*)malloc(sizeof(Stack));
	q->data=n;
	q->next=*p;
	*p=q;
}
int pop(Stack**p)
{
	Stack*r;
	int temp;
	if(*p==NULL)
	{
		printf("Pop Not Possible");
	}
	else
	{
		r=*p;
		temp=r->data;
		*p=r->next;
		free(r);
	}
	return(temp);
}
int peek(Stack*p)
{
	if(p==NULL)
	{
		printf("Null List");
	}
	else
	{
		int temp;
		temp=p->data;
		printf("peek is %d",temp);
	}
}
void is_empty(Stack*p)
{
	if(p==NULL)
	{
		printf("Stack Is empty");
	}
	else
	{
		printf("Stack is not empty");
	}
}
void display(Stack*p)
{
	if(p==NULL)
	{
		printf("NULL LIST");
	}
	else
	{
		do
		{
			printf("%d\n",p->data);
			p = p->next;
		}while(p!=NULL);
	}
}
int main()
{
	Stack*head=NULL;
	int choice,n,p;
	printf("Stack using LL");
	printf("\n");
	do
	{
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.PEEK");
		printf("\n4.Is Empty");
		printf("\n5.DISPLAY");
		printf("\n6.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data:");
				scanf("%d",&n);
				push(&head,n);
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				peek(head);
				break;
			case 4:
				is_empty(head);
				break;
			case 5:
				display(head);
				break;
			default:
				printf("Invalid Choice");			
		}
		
	}while(1);
}

