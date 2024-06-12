#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
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
struct Node *start=NULL;
int main()
{
	int ch;
	printf("\n1.Create\n");
	printf("2.Traverse\n");
	printf("3.Insert at Begin\n");
	printf("4.Insert at End\n");
	printf("5.Insert at Location\n");
	printf("6.Delete at Begin\n");
	printf("7.Delete at End\n");
	printf("8.Delete at Location\n");
	printf("9.Exit\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				traverse();
				break;
			case 3:
				insertatbegin();
				break;
			case 4:
				insertatend();
				break;
			case 5:
				insertatloc();
				break;
			case 6:
				deleteatbegin();
				break;
			case 7:
				deleteatend();
				break;
			case 8:
				deleteatloc();
				break;
			case 9:
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
			printf("Enter the value to keep in the node: ");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			temp->prev=NULL;
			start=temp;
			for(index=1;index<total;index++)
			{
				newnode=(struct Node*)malloc(sizeof(struct Node));
				printf("Enter value to insert in created node:");
				scanf("%d",&item);
				newnode->info=item;
				newnode->next=NULL;
				newnode->prev=temp;
				temp->next=newnode;
				temp=temp->next;
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
	temp=start;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		temp=start;
		printf("The list is:\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
		temp=start;
		printf("\nReverse of list is:\n");
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->prev;
		}
		printf("\n");
	}
}
void insertatbegin()
{
	int item;
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter an item to insert: ");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			start->prev=newnode;
			newnode->next=start;
			start=newnode;
		}
	}
}
void insertatend()
{
	int item;
	struct Node *newnode,*temp;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter an item to insert: ");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}
void insertatloc()
{
	struct Node *newnode,*temp,*ptr;
	int item,i=0,loc;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter an item to insert: ");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			printf("Enter location to insert: ");
			scanf("%d",&loc);
			temp=start;
			while(temp!=NULL&&i!=loc)
			{
				i++;
				ptr=temp;
				temp=temp->next;
			}
			if(temp==NULL)
			{
				printf("Node is not present\n");
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
}
void deleteatbegin()
{
	struct Node *temp;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		printf("Deleted item is: %d\n",temp->info);
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
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf("Deleted element is: %d\n",temp->info);
		free(temp);
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
	else
	{
		temp=start;
		printf("Enter location to delete: ");
		scanf("%d",&loc);
		while(temp->next!=NULL && i!=loc)
		{
			ptr=temp;
			temp=temp->next;
			i++;
		}
		if(temp==NULL)
		{
			printf("Node is not present\n");
		}
		else
		{
			ptr->next=temp->next;
			ptr=temp->next;
			ptr->prev=temp->prev;
			printf("Deleted element is %d\n",temp->info);
			free(temp);
		}
	}
}
