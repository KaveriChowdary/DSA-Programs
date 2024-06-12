#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
struct entry
{
	char name[50];
	char nickname[50];
	char email[50];
	char address[50];
	char city[50];
	char contact[50];
	char pin[50];
	struct entry *lptr;
	struct entry *rptr;
}*temp,*newe,*l,*r;
typedef struct entry *list;
void newentry();
void display(char n[50]);
void deletentry(char n[50]);
void displayall();
void makempty();
int isempty();
void saventry();                                                                                                                           
void deleteall();
void newentry()
{
	char a[50],b[50],f[50],g[50],c[50],d[50],e[50];
	int i,k=0;
	printf("\nEnter the data for new entry:");
	printf("\nName:");
	scanf("%s",a);
	printf("\nNickname:");
	scanf("%s",b);
	printf("\nEmail-id:");
	scanf("%s",c);
	printf("\nAddress:");
	scanf("%s",d);
	printf("\nCity:");
	scanf("%s",e);
	printf("\nContact no.:");
	scanf("%s",f);
	printf("\nPincode:");
	scanf("%s",g);
	newe=(struct entry*)malloc(sizeof(struct entry));

	for(i=0;i<50;i++)
	{
		newe->name[i]=a[i];
		newe->nickname[i]=b[i];
		newe->email[i]=c[i];
		newe->address[i]=d[i];
		newe->city[i]=e[i];
		newe->contact[i]=f[i];
		newe->pin[i]=g[i];
	}
	if(isempty())
	{
		newe->lptr=newe->rptr=NULL;
		l=r=newe;
		printf("\nyour entry is added");
	}
	else
	{
		temp=l;
		while(temp!=NULL)
		{
			i=stricmp(newe->name,temp->name);
			if(i<0)
			break;
			else if(i>0)
			temp=temp->rptr;
			else if(i==0)
			{
				printf("Name already exists,Try other name");
				k=1;
				break;
			}
		}
		if(k!=1)
		{
			if(temp==l)
			{
				newe->lptr=NULL;
				newe->rptr=l;
				l->lptr=newe;
				l=newe;
				printf("\nEntry is added");
			}
			else if(temp==NULL)
			{
				newe->rptr=NULL;
				newe->lptr=r;
				r->rptr=newe;
				r=newe;
				printf("\nEntry is added");
			}
			else
			{
				newe->rptr=temp;
				newe->lptr=temp->lptr;
				temp->lptr=newe;
				(newe->lptr)->rptr=newe;
				printf("\nEntry is added");
			}
		}
	}
}
	void displayall()
	{
		int n=1;
		if(!isempty())
		{
			temp=l;
			while(temp!=NULL)
			{
				printf("\n[%d] \nName:%s \nNickname:%s \nEmail ID:%s \nAddress:%s \nCity:%s \nContact:%s \nPin:%s",n,temp->name,temp->nickname,temp->email,temp->address,temp->city,temp->contact,temp->pin);
				temp=temp->rptr;
				n++;
			}
		}
		else
		printf("\nAddress book is empty");
	}
	void deletentry(char n[50])
	{
		int i;
		if(isempty())
		printf("\nAddress book is empty");
		else
		{
			temp=l;
			while(temp!=NULL)
			{
				i=stricmp(temp->name,n);
				{
					if(l==r)
					{
						l=r=NULL;
						printf("\nEntry deleted");
						break;
					}
					else if(temp==l)
					{
						l=l->rptr;
						l->lptr=NULL;
						printf("\nEntry deleted");
						break;
					}
					else if(temp==r)
					{
						r=r->rptr;
						r->rptr=NULL;
						printf("\nEntry deleted");
						break;
					}
					else
					{
						(temp->lptr)->rptr=temp->rptr;
						(temp->rptr)->lptr=temp->lptr;
						printf("\nEntry deleted");
						break;
					}
				}
				temp=temp->rptr;
			}
			if(temp==NULL)
			printf("\nNOT found");
		}
	}
	int isempty()
	{
		return l==NULL;
	}
	void makempty()
	{
		l=r=NULL;
		printf("\nAddress book is emptied");
	}
	void display(char n[50])
	{
		int i,p=1;
		if(isempty())
		printf("\nAddress book is empty");
		else
		{
			temp=l;
			while(temp!=NULL)
			{
				i=stricmp(temp->name,n);
				{
					if(p==1)
					printf("\nEntry is found at%dst position",p);
					else if(p==2)
					printf("\nEntry is found at%dnd position",p);
					else if(p==3)
					printf("\nEntry is found at%drd position",p);
					else
					printf("\nEntry is found at%dth position",p);
					printf("\nName:%s Nickname:%s Email ID:%s  Address:%s City:%s Contact:%s Pin:%s",temp->name,temp->nickname,temp->email,temp->address,temp->city,temp->contact,temp->pin);
					break;
				}
				temp=temp->rptr;
				p++;
			}
			if(temp==NULL)
			printf("\nEntry not found");
		}
		}	
	void saventry()
	{
		char n[50];
		int c;
		list t;
		int i;t=l;
		printf("\nEnter the name of the person");
		scanf("%s",n);
		if(isempty())
		printf("\nAddress book is empty");
		else
		{
			FILE *f;
			f=fopen("entry.c","a");
			while(t!=NULL)
			{
				i=stricmp(t->name,n);
				if(i==0)
				{
					fprintf(f,"%s %s %s %s %s %s %s",t->name,t->nickname,t->email,t->address,t->city,t->contact,t->pin);
					printf("\nEntry saved");
					printf("\nDo you want to add another entry(y/n):");
					scanf("%d",&c);
					if(c==1)
					saventry();
					else if(c==2)
					break;
				}
				t=t->rptr;
			}
			fclose(f);
			if(t==NULL)
			printf("\nEntry not found");
		}
 }
	void deleteall()
	{
		FILE *f;
		f=fopen("entry.c","w");
		fclose(f);
		printf("\nAll saved files are deleted");
	}
void main()
	{
		int l=1;
		char n[50];
		while(l!=8)
		{
		//	clrscr();
			printf("\n\n*TELEPHONE DIRECTORY*");
			printf("\nEnter your choice:");
			printf("\n");
			printf("(1)-New entry");
			printf("\n");
			printf("(2)-Delete an entry");
			printf("\n");
			printf("(3)-Display all entry");
			printf("\n");
			printf("(4)-Empty the directory");
			printf("\n");
			printf("(5)-Save entry");
			printf("\n");
			printf("(6)-exit");
			printf("\n");
			printf("\n*************************\n");
			scanf("%d",&l);
			switch(l)
			{
				case 1:
				newentry();
				getch();
				break;
				case 2:
				printf("\nEnter the name of person to delete:");
				scanf("%s",&n);
				deletentry(n);
				getch();
				break;
				case 3:
				displayall();
				getch();
				break;
				case 4:
				makempty();
				getch();
				break;
				case 5:
				saventry();
				getch();
				break;
				case 6:
				printf("\nProgram ends here!!THANK YOU.");
				getch();
				break;
				case 'a':
					isempty();
					break;
				default:
					printf("Invalid Input");
					getch();
					break;
			}
		}
		getch();
	}






