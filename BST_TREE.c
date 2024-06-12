# include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;   
	struct Node *lchild;
	struct Node *rchild;
};
struct Node *root = NULL;

void insert();
void delete1();
void inorder(struct Node *);
void preorder(struct Node *);
void postorder(struct Node *);
void casea(struct Node *,struct Node *);
void caseb(struct Node *,struct Node *);
void casec(struct Node *,struct Node *);
void main()
{
	int ch;
	printf("\n 1. INSERT");
	printf("\n 2. DELETE");
	printf("\n 3. INORDER TRAVERSE");
	printf("\n 4. PREORDER TRAVERSE");
	printf("\n 5. POSTORDER TRAVERSE");
	printf("\n 6. EXIT");
	while(1)
	{
		printf("\n\n Make your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delete1();
				break;
			case 3:
				if(root==NULL)
				{
					printf("\n Tree Is Empty");
				}
				else
				{
				inorder(root);
			    }
				break;
			case 4:
				if(root == NULL)
				{
					printf("\n Tree Is Empty");
				}
				else
				{
					preorder(root);
	
	
				}
				break;
			case 5:
				if(root == NULL)
				{
					printf("\n Tree Is Empty");
				}
				else
				{
					postorder(root);
				}
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n Invalid Choice");
				break;
		}
	}
}

void insert()
{
	struct Node *temp,*ptr,*par;
	int item;
	temp = (struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\n memory is not allocated");
		
	}
	else
	{
		printf("\n Enter Data:");
		scanf("%d",&item);
		temp->info=item;
		temp->lchild=NULL;
		temp->rchild=NULL;
		if(root == NULL)
		{
			root = temp;
		}
		else
		{
			ptr=root;
			while(ptr!=NULL)
			{
				par=ptr;
				if(item<ptr->info)
				{
					ptr=ptr->lchild;
				}
				else if(item>ptr->info)
				{
					ptr=ptr->rchild;
				}
				else
				{
					printf("\n Duplicate Elements cannot be Inserted");
					break;
				}
			}
			if(ptr==NULL)
			{
				if(item<par->info)
				{
					par->lchild=temp;
				}
				else
				{
					par->rchild=temp;
				}
			}
		}
	}
}

void delete1()
{
	struct Node *temp,*ptr,*par;
	int item;
	if(root == NULL)
	printf("\n Tree Is Empty");
	else
	{
		ptr=root;
		par=NULL;
		printf("\n Enter the Value to Delete:");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->info == item)
			{
			 break;	
			}
			par = ptr;
			if(item<ptr->info)
			{
				ptr = ptr->lchild;
			}
			else
			{
				ptr = ptr->rchild;
			}
		}
		if(ptr == NULL)
		{
			printf("\n Element IS Not PRESENT");
		}
		printf("\n The Deleted Value is =%d",ptr->info);
		if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
		{
			casea(par,ptr);
			}
		else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
		{
			casec(par,ptr);
			}	
		else
		{
			//printf("\n hii");
			caseb(par,ptr);
		}
	}
}

void casea(struct Node *par,struct Node *ptr)
{
	if(par==NULL)
	{
		root = NULL;
		free(ptr);
	}
	else if(ptr->info<par->info)
	{
		par->lchild = NULL;
	}
	else
	{
		par->rchild = NULL;
	}
	free(ptr);
}

void caseb(struct Node *par,struct Node *ptr)
{
    struct Node *child;
    if(ptr->lchild!=NULL)
    {
    	child = ptr->lchild;
	}
	else
	{
		child = ptr->rchild;
	}
	if(ptr == NULL)
	{
		root = child;
		free(ptr);
	}
	else
	{
		if(ptr == par->lchild)
		{
			par->lchild = child;
		}
		else
		{
			par->rchild = child;
		}
		free(ptr);
	}
}

void casec(struct Node *par,struct Node *ptr)
{
	struct Node *pptr,*ppar;
	pptr = ptr->rchild;
	ppar = ptr;
	while(pptr->lchild!=NULL)
	{
		ppar = pptr;
		pptr = pptr->lchild;
	}
	ptr->info = pptr->info;
	if(pptr->rchild!=NULL)
	{
		caseb(ppar,pptr);
	}
	else
	{
		casea(ppar,pptr);
	}
}

void inorder(struct Node *temp)
{
 if(temp!=NULL)
 {
 	inorder(temp->lchild);//left
 	printf("%d\t",temp->info);//ROOT
 	inorder(temp->rchild);//right
	 }	
}

void preorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->info);//root
		preorder(temp->lchild);//left
		preorder(temp->rchild);//right
	}
}

void postorder(struct Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);//left
		postorder(temp->rchild);//right
		printf("%d\t",temp->info);//root
	}
}
