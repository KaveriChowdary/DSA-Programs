//program on single linked list
#include<stdlib.h>
#include<stdio.h>
void create();
void insertatbegin();
void insertatend();
void insertatlocation();
void deleteatbegin();
void deleteatend();
void deleteatlocation();
void traverse();
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
int main()
{
	int ch;
	printf("\n 1.insertatbegin");
	printf("\n 2.insertatend");
	printf("\n 3.insertatlocation");
	printf("\n 4.deleteatbegin");
	printf("\n 5.deleteatend");
	printf("\n 6.deleteatlocation");
	printf("\n 7.traverse");
	printf("\n 8.create");
	printf("\n 9.end of the program");
	while(1)
	{
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				insertatbegin();
				break;
			}
			case 2:{
				insertatend();
				break;
			}
			case 3:{
				insertatlocation();
				break;
			}
			case 4:{
				deleteatbegin();
				break;
			}
			case 5:{
				deleteatend();
				break;
			}
			case 6:{
				deleteatlocation();
				break;
			}
			case 7:{
				traverse();
				break;
			}
			case 8:{
				create();
				break;
			}
			case 9:{
		            exit(0);
			}
			default:{
				printf("\n invalid choice");
			}
		}
	}
}
void create()
{
	struct node *temp,*newnode;
	int total,item,i;
	if(start==NULL)
	{
		printf("enter total no.of nodes you want to keep in list\n");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("size must be greater than 0\n");
		}
		else
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("enter item to insert in node\n");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			start=temp;
			for(i=2;i<=total;i++)
			{
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("enter the item\n");
				scanf("%d",&item);
				newnode->info=item;
				newnode->next=NULL;
				temp->next=newnode;
				temp=newnode;
			}
			printf("list is created\n");
		}
	}
	else
	{
		printf("list is already present\n");
	}
}
void insertatbegin()
{
	struct node *newnode;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
  	if(newnode==NULL)
	{
		printf("\n memory is not allocated\n");
	}
	else
	{
		printf("\n enter data to insert at begin\n");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
	}
}
void insertatend()
{
	struct node *newnode,*temp;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
	   printf("\n memory not allocated");
	}
	else
	{
		printf("\n enter data to insert at end\n");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
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
		}
}
}
void insertatlocation()
{
	struct node *newnode,*temp,*ptr;
	int item,loc,count=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		 printf("\n memory not allocated");
	}
	else
	{
		printf("\n enter data to insert \n");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			printf("\n enter the location at which you want to insert\n");
			scanf("%d",&loc);
			temp=start;
			while(temp!=NULL&&count!=loc)
			{
				count++;
				ptr=temp;
				temp=temp->next;
			}
			if(temp==NULL)
			{
				printf("\n node is not present\n");
			}
			else
			{
				ptr->next=newnode;
				newnode->next=temp;
			}
		}
	}
}
void deleteatbegin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("n list is empty\n");
	}
	else
	{
		temp=start;
		start=start->next;
		printf("\n deleted value is%d\n",temp->info);
		free(temp);
	}
}
void deleteatend()
{
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=start;
		if(start->next==NULL)
		{
			start=NULL;
		}
		else
		{ 
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
	}
		printf("the deleted value is %d\n",temp->info);
		free(temp);
	}
}
void deleteatlocation()
{
	struct node *temp,*ptr;
	int loc,count=1;
	if(start==NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		temp=start;
		if(start->next==NULL)
		{
			start=NULL;
			printf("\n the deleted value%d:",temp->info);
			free(temp);
		}
		else
		{
			printf("\n enter the location from which you want to delete:\n");
			scanf("%d",&loc);
			temp=start;
			while(temp!=NULL&&count!=loc)
			{
				ptr=temp;
				temp=temp->next;
				count++;
			}
			if(temp==NULL)
			{
				printf("\n node not present\n");
			}
			else
			{
				ptr->next=temp->next;
				printf("\n the deleted node:%d",temp->info);
				free(temp);
			}
		}
	}
}
void traverse()
{
	struct node*temp;
	if(start==NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		temp=start;
		printf("\n the values of linkded list are:");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
	}
}
