//program on circular double linked list
#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void reverse();
void insertatbegin();
void insertatend();
void insertatloc();
void deleteatbegin();
void deleteatend();
void deleteatloc();
struct Node
{
	int info;
	struct Node *next;
	struct Node *prev;
};
int item;
struct Node *start=NULL,*end=NULL;
main()
{
	int choice;
	printf("1 Create\n");
	printf("2 Traverse\n");
	printf("3 Reverse\n");
	printf("4 Insert at Begin\n");
	printf("5 Insert at End\n");
	printf("6 Insert at specified location\n");
	printf("7 Delete at Begin\n");
	printf("8 Delete at End\n");
	printf("9 Delete at specified location\n");
	printf("10 Exit\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				traverse();
				break;
			case 3:
				reverse();
				break;
			case 4:
				insertatbegin();
				break;
			case 5:
				insertatend();
				break;
			case 6:
				insertatloc();
				break;
			case 7:
				deleteatbegin();
				break;
			case 8:
				deleteatend();
				break;
			case 9:
				deleteatloc();
				break;
			case 10:
				exit(0);
			default:
				printf("PLEASE ENTER VALID OPTION\n");
		}
	}
}
void create()
{
	int total,index,item;
	struct Node *temp,*newnode;
	if(start==NULL)
	{
		printf("Enter no.of nodes you want: ");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("LIST MUST BE GREATER THAN ZERO\n");
		}
		else
		{
			temp=(struct Node*)malloc(sizeof(struct Node));
			printf("Enter the value to keep in the node : ");
			scanf("%d",&item);
			temp->info=item;
			temp->next=temp;
			temp->prev=temp;
			start=temp;
			for(index=2;index<=total;index++)
			{
				newnode=(struct Node*)malloc(sizeof(struct Node));
				printf("Enter the item : ");
				scanf("%d",&item);
				newnode->info=item;
				newnode->next=start;
				newnode->prev=temp;
				temp->next=newnode;
				start->prev=newnode;
				temp=newnode;
			}
		}
		printf("List is created\n");
	}
	else
	{
		printf("List is already present\n");
	}
}
void traverse()
{
	struct Node *temp;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		temp=start;
		printf("List is:\n");
		do
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}while(temp!=start);
		printf("\n");
	}
}
void reverse()
{
	struct Node *temp;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		temp=start;
		printf("List is:\n");
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		do
		{
			printf("%d\t",temp->info);
			temp=temp->prev;
		}while(temp->next!=start);
		printf("\n");
	}
}
void insertatbegin()
{
	struct Node *newnode,*temp;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter an item to insert: ");
	scanf("%d",&item);
	newnode->info=item;
	newnode->next=newnode;
	newnode->prev=newnode;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		newnode->next=start;
		start->prev=newnode;
		newnode->prev=temp;
		start=newnode;
		temp->next=start;
	}
}
void insertatend()
{
	struct Node *newnode,*temp;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter item to insert: ");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
		newnode->prev=newnode;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			newnode->prev=temp;
			temp->next=newnode;
			newnode->next=start;
			start->prev=newnode;
		}
	}
}
void insertatloc()
{
	struct Node *newnode,*temp,*ptr;
	int i=1,loc;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter item to insert: ");
	scanf("%d",&item);
	newnode->info=item;
	newnode->next=newnode;
	newnode->prev=newnode;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		printf("Enter location to insert: ");
		scanf("%d",&loc);
		temp=start;
		do
		{
			i++;
			ptr=temp;
			temp=temp->next;
		}while(temp!=start&&i!=loc);
		if(temp==start)
		{
			printf("Node does not exist\n");
		}
		else
		{
			newnode->next=temp;
			temp->prev=newnode;
			ptr->next=newnode;
			newnode->prev=ptr;
		}
	}
}
void deleteatbegin()
{
	struct Node *temp,*ptr;
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else if(start->next==start)
	{
		printf("the deleted value is:%d",start->info);
		start=NULL;
	}
	else
	{
		temp=start;
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		start=start->next;
		start->prev=start;
		ptr->next=start;
		printf("\n deleted value is%d\n",temp->info);
		free(temp);
	}
}
void deleteatend()
{
	struct Node *temp,*ptr;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else if(start->next==start)
	{
		printf("Deleted item is %d\n",start->info);
		start=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=start;
		start->prev=ptr;
		printf("Deleted item is %d\n",temp->info);
	}
}
void deleteatloc()
{
	struct Node *temp,*ptr;
	int i=1,loc;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else if(start->next==start)
	{
		printf("Deleted item is %d\n",start->info);
		start=NULL;
	}
	else
	{
		printf("Enter location to delete: ");
		scanf("%d",&loc);
		temp=start;
		do
		{
			ptr=temp;
			i++;
			temp=temp->next;
		}while(temp!=start&&i!=loc);
		if(temp==start)
		{
			printf("Node does not exist\n");
		}
		
		else
		{
			ptr->next=temp->next;
			ptr=temp->next;
			ptr->prev=temp->prev;
			printf("Deleted element is %d\n",temp->info);
		}
	}
}
