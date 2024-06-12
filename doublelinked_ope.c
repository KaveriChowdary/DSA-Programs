//program on double linked list
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
	struct node *next,*prev;
};
struct node *start=NULL;
int main()
{
	int ch;
	printf("\n 1.create");
	printf("\n 2.insert at begin");
	printf("\n 3.insert at end");
	printf("\n 4.insert at location");
	printf("\n 5.delete at begin");
	printf("\n 6.delete at end");
	printf("\n 7.delete at location");
	printf("\n 8.traverse");
	printf("\n 9.end of the program");
	while(1)
	{
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				create();
				break;
			}
			case 2:{
				insertatbegin();
				break;
			}
			case 3:{
				insertatend();
				break;
			}
			case 4:{
				insertatlocation();
				break;
			}
			case 5:{
				deleteatbegin();
				break;
			}
			case 6:{
				deleteatend();
				break;
			}
			case 7:{
				deleteatlocation();
				break;
			}
			case 8:{
				traverse();
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
			temp=(struct node*)malloc(sizeof(struct node));//dynamic memory allocation
			printf("enter item to insert in node\n");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			temp->prev=NULL;
			start=temp;
			for(i=2;i<=total;i++)
			{
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("enter the item\n");
				scanf("%d",&item);
				newnode->info=item;
				newnode->next=NULL;
				newnode->prev=temp;
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
		newnode->prev=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start->prev=newnode;
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
		newnode->prev=NULL;
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
				newnode->prev=ptr;
				temp->prev=newnode;
			}
		}
	}
}
void deleteatbegin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else if(start->next==NULL)
	{
		printf("the deleted value is:%d",start->info);
		start=NULL;
	}
	else
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
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
	else if(start->next==NULL)
	{
		printf("the deleted value is:%d",start->info);
		start=NULL;
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
			printf("\n the deleted value: %d",temp->info);
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
			else if(temp->next==NULL)
			{
				deleteatend();
			}
			else
			{	
			ptr->next=temp->next;
			temp->next->prev=ptr;
			//ptr=temp->next;
			//ptr->prev=temp->prev;
			printf("Deleted element is %d\n",temp->info);
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
		printf("\n the values of linked list are:");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
		printf("\n the values in reverse order:");
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp!=NULL)
		{
			printf("%d\t",temp->info); 
			temp=temp->prev;
		}
	}
}

