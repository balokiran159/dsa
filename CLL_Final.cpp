//Circular Linkedlist insert and delete all position.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
typedef struct node {
						int data;
						struct node*next;
					}Node;
void cinsert_begin(Node**p,int n)
{
	Node*q,*r;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	if(*p==NULL)
	{
		q->next=q;
		*p=q;
	}
	else
	{
		r=*p;
		while(r->next!=*p)
		{
			r=r->next;
		}
		r->next=q;
		q->next=*p;
		*p=q;
	}
}
void cdisplay(Node*p)
{
	Node *r=p;
	if(p==NULL)
	{
		printf("Null List");
	}
	else
	{
		do
		{
			printf("%d  ",p->data);
			p=p->next;
		}while(p!=r);
	}
}
int ccounter(Node*p)
{
	int c=0;
	while(p!=NULL)
	{
		p=p->next;
		c++;
	}
	return c;
}
void cinsert_end(Node**p,int n)
{
	Node*q,*r;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	if(*p==NULL)
	{
		q->next=q;
		*p=q;
	}
	else
	{
		r=*p;
		while(r->next!=*p)		
		{
			r=r->next;
		}
		r->next=q;
		q->next=*p;
	}
}
void cinsert_nth(Node**p,int n,int pos)
{
	Node*q,*r=*p;
	int i;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	if(pos==1)
	{
		if(*p==NULL)
		{
			q->next=q;
			*p=q;
		}
		else
		{
			while(r->next!=*p)
			{
				r=r->next;
			}
			r->next=q;
			q->next=*p;
			*p=q;
		}
	}
	else
	{
		for(i=0;i<pos-2;i++)
		{
			r=r->next;
		}
		q->next=r->next;
		r->next=q;
	}
}
void cdelete_beg(Node**p)
{
	Node *q,*r;
	if(*p==NULL)
	{
		printf("Null List! Deletion Not Possible");
	}
	else if(r->next=r)
	{
		free(r);
		*p=NULL;
	}
	else
	{
		r=*p;
		*p=r->next;
		q=*p;
		while(q->next!=*p)
		{
			q=q->next;
		}
		q->next=*p;
		free(r);
	}
}
void cdelete_end(Node**p)
{
	Node *r;
	if(*p==NULL)
	{
		printf("Null List! Deletion Not Possible");
	}
	else if((*p)->next==*p)
	{
		free(*p);
		*p=NULL;
	}
	else
	{
		r=*p;
		while(r->next->next!=*p)
		{
			r=r->next;
		}
		free(r->next);
		r->next=*p;
	}
}
void cdelete_anynode(Node **p,int n)
{
	Node *q,*r=*p,*s=*p;
	if(*p==NULL)
	{
		printf("Null List!Deletion Not Possible");
	}
	else
	{
		while(r->data!=n)
		{
			r=r->next;
		}
		q=r->next;
		while(s->next!=r)
		{
			s=s->next;
		}
		s->next=q;
		free(r);
	}
}
void cdelete_nth(Node**p,int pos)
{
	Node *q,*r=*p;
	int i;
	if(*p==NULL)
	{
		printf("Null List!Deletion Not Possible");
	}
	else if(pos==1)
	{
		*p=r->next;
		free(r);
	}
	else
	{
		for(i=0;i<pos-2;i++)
		{
			r=r->next;
		}
		q=r->next;
		r->next=q->next;
		free(q);
	}
}
int main()
{
	Node *head=NULL;
	int num,loc,choice;
	char opt;
	printf("PROGRAM TO IMPLEMENT CIRCULAR LINKED LIST");
	printf("\n=======================================");
	do
	{
		printf("\n1.Create/Appending The List");
		printf("\n2.Insert Node At Beginning");
		printf("\n3.Insert Node At Nth Position");
		printf("\n4.Delete First Node");
		printf("\n5.Delete Last Node");
		printf("\n6.Delete the Node whose Data Matches with given Data");
		printf("\n7.Delete Nth Node");
		printf("\n8.Displaying The List");
		printf("\n9.Exit");
		
		printf("\n\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				do
				{
					printf("Enter The Data : ");
					scanf("%d",&num);
					cinsert_end(&head,num);
					printf("Enter More Data (Y/N)? : ");
					fflush(stdin);
					opt=getchar();
				}while(toupper(opt)!='N');
				break;
			case 2:
				printf("Enter The Data : ");
				scanf("%d",&num);
				cinsert_begin(&head,num);
				break;
			case 3:
				printf("\nEnter The Node Number Before Which New Node Will Be Inserted : ");
				scanf("%d",&loc);
				printf("\nEnter The Data : ");
				scanf("%d",&num);
				cinsert_nth(&head,loc,num);
				break;
			case 4:
				cdelete_beg(&head);
				break;
			case 5:
				cdelete_end(&head);
				break;
			case 6:
				printf("\nEnter The Data You Want To Delete : ");
				scanf("%d",&num);
				cdelete_anynode(&head,num);
				break;
			case 7:
				printf("\nEnter The Position Which Will Be Deleted : ");
				scanf("%d",&loc);
				cdelete_nth(&head,loc);
				break;
			case 8:
				cdisplay(head);
				break;
			case 9:
				printf("\nQuiting........");
				getch();
				exit(0);
			default:
				printf("Invalid Choice. Please Enter Correct Choice");
				getch();
		}
	}while(1);
} 
