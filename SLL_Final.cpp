#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}Node;
/*void create(Node**p)
{
	Node*cur;
	cur=(Node*)malloc(sizeof(Node));
	*p=cur;
	char ch;
	while(1)
	{
		printf("Enter The Data:");
		scanf("%d",&cur->data);
		printf("Continue . . . (Y or N)? :");
		fflush(stdin);
		scanf("%c",&ch);
		if(toupper(ch)=='Y')
		{
			cur->next=(Node*)malloc(sizeof(Node));
			cur=cur->next;
		}
		else
		{
			cur->next=NULL;
			break;
		}
	}
}*/
void display(Node*p)
{
	if(p==NULL)
	{
		printf("NULL List.\n");
		return;
	}
	else
	{
		//while(p->next!=NULL)
		while(p!=NULL)
		{
			printf("%d   ",p->data);
			p=p->next;
		}
		//printf("%d  ",p->data);
	}
	
}
int counter(Node*p)
{
	int c=0;
	while(p!=NULL)
	{
		p=p->next;
		c++;
	}
	return c;
}
void insert_first(Node**p,int n)
{
	Node*q;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	q->next=*p;
	*p=q;
}
void insert_last(Node**p, int n)
{
	Node*q,*r;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	q->next=NULL;
	if(*p==NULL)
	{
		*p=q;
	}
	else
	{
		r=*p;
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=q;
	}
}
void insert_nth(Node**p,int pos,int n)
{
	Node*q,*r;
	if(pos>counter(*p)+1)
	{
		printf("Invalid position. Please Put Valid position.\n");
		return;
	}
	q=(Node*)malloc(sizeof(Node));
	int i;
	q->data=n;
	if(*p==NULL||pos==1)
	{
		q->next=*p;
		*p=q;
	}
	else
	{
		r=*p;
		for(i=0;i<pos-2;i++)
		{
			r=r->next;
		}
		q->next=r->next;
		r->next=q;
	}
}
void delete_first(Node**p)
{
	Node*r;
	if(*p==NULL)
	{
		printf("Deletation not possible\n");
		return;
	}
	else
	{
		r=*p;
		*p=r->next;
		free(r);
	}
}
void delete_last(Node**p)
{
	Node*r;
	if(*p==NULL)
	{
		printf("Deletation not possible\n");
	}
	else if ((*p)->next==NULL)
	{
		free(*p);
		*p=NULL;
	}
	else
	{
		r=*p;
		while(r->next->next!=NULL)
		{
			r=r->next;
		}
		free(r->next);
		r->next=NULL;
	}
}
void delete_nth(Node**p,int pos)
{
	Node*q,*r=*p;
	int i;
	if(pos>counter(*p)+1)
	{
		printf("Invalid position. Please Put Valid position.\n");
		return;
	}
	if(*p==NULL)
	{
		printf("Deletation not possible\n");
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
	Node*head=NULL;
	int n,opt,pos;
	char ch;
	printf("=====Single LinkedList=====");
	while(1)
	{
		printf("\n1.Create a LL");
		printf("\n2.Display");
		printf("\n3.Exit");
		printf("\n4.Insert First");
		printf("\n5.Insert Last");
		printf("\n6.Insert Nth");
		printf("\n7.Delete First");
		printf("\n8.Delete Last");
		printf("\n9.Delete Nth");
		printf("\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			/*case 1:
				create(&head);
				break;*/
			case 1:
				do
				{
					printf("Enter the data:");
					scanf("%d",&n);
					insert_last(&head,n);
					printf("Continue . . .(Y or N): ");
					fflush(stdin);
					ch=getchar();
				}while(toupper(ch)!='N');
				break;
			case 2:
				display(head);
				break;
			case 3:
				exit(1);
				break;
			case 4:
				printf("Enter the Data:");
				scanf("%d",&n);
				insert_first(&head,n);
				break;
			case 5:
				printf("Enter the Data:");
				scanf("%d",&n);
				insert_last(&head,n);
				break;
			case 6:
				printf("Enter the position you want to enter The Data:");
				scanf("%d",&pos);
				printf("Enter the Data:");
				scanf("%d",&n);
				insert_nth(&head,pos,n);
				break;
			case 7:
				delete_first(&head);
				break;
			case 8:
				delete_last(&head);
				break;
			case 9:
				printf("Enter the position you want to delete:");
				scanf("%d",&pos);
				delete_nth(&head,pos);
				break;
			default:
				printf("You enter wrong choice:");	
		}
	}
	return 0;
}
