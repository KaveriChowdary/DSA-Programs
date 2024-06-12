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
void reverse();
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
	printf("\n 9.reverse\n");
	printf("\n 10.end of the program");
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
				reverse();
				break;
			}
			case 10:{
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
			temp->next=temp;
			temp->prev=temp;
			start=temp;
			for(i=2;i<=total;i++)
			{
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("enter the item\n");
				scanf("%d",&item);
				newnode->info=item;
				newnode->next=start;
				newnode->prev=start;
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
	struct node *newnode,*temp;
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
		newnode->next=newnode;
		newnode->prev=start;
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
			start=newnode;
			temp->next=newnode;//modified
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
		newnode->next=newnode;
		newnode->prev=start;
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
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=start;
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
		newnode->next=newnode;
		newnode->prev=start;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			printf("\n enter the location at which you want to insert\n");
			scanf("%d",&loc);
			temp=start;
				do{
				count++;
				ptr=temp;
				temp=temp->next;
			}while(temp!=start&&count!=loc);
			if(temp==start)
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
	struct node *temp,*ptr;
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
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n list is empty");
	}
	else if(start->next==start)
	{
		printf("the deleted value is:%d",start->info);
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
		if(start->next==start)
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
			do{
				ptr=temp;
				temp=temp->next;
				count++;
			}while(temp!=start&&count!=loc);
			if(temp==start)
			{
				printf("\n node not present\n");
			}
			else
			{	
			ptr->next=temp->next;
			temp->next->prev=ptr;
			printf("Deleted element is %d\n",temp->info);
			free(temp);
			}
		}
	}
}
void traverse()
{
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		temp=start;
		printf("\n the values of linked list are:");
	   do{
			printf("%d\t",temp->info);
			temp=temp->next;
		}while(temp!=start);
	}
}
void reverse()
{
	struct node *temp;
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

