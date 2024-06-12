#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size],infix[size],postfix[size];
int top=-1;
void push(char);
int pop();
int isempty();
void intopost();
int space(char);
void print();
int precedence(char);
int main()
{
	printf("enter the infix expression\n");
	gets(infix);
	intopost();
	print();
	return 0;
}
void intopost()
{
	int i,j=0;
	char sym,next,postfix[size];
	for(i=0;i<strlen(infix);i++)
	{
		sym=infix[i];
		//if symbol is not whitespace
		if(!space(sym))
		{
			switch(sym)
			{
				case '(':{
					push(sym);
					break;
				}
				case ')':{
					while((next==pop()) != '(')
					postfix[j]=next;
					j++;
					break;
				}
				case '+':{
				case '-':
				case '*':
				case '/':
				case '^':
					while(!isempty()&& precedence(stack[top])>=precedence(sym))
					{
					postfix[j]=pop();
					j++;
				}
					push(sym);
					break;
				}
				default: {//if sym is operand
				postfix[j]=sym;
				j++;
			}
			}
		}
	}
	while(!isempty())
	postfix[j]=pop();
	j++;
	postfix[j]='\0';
}
int space(char c)
{
// if sym is a blank space or tab
if(c==' ' || c== '\t')
return 1;
else
return 0;	
}
int precedence(char sym)
{
	switch(sym)
	{
		case '^':{
		    return 3;
			break;
		}
		case '/':{
		case '*':
			return 2;
			break;
		}
		case '+':{
		case '-':
			return 1;
			break;
		}
		default:
			return 0;
	}
}
void print()
{
	int i=0;
	printf("the equivalent postfix expression is :");
	while(postfix[i]!='\0')
	{
		printf("%c",postfix[i]);
		i++;
	}
}
void push(char c)
{
	if(top==size -1)
	{
		printf("stack overflow\n");
		return;
	}
	top++;
	stack[top]=c;
}
int pop()
{
	if(top==-1)
	{
		printf("underflow\n");
	}
	else
	{
	top--;
    }
}
int isempty()
{
	if(top==-1)
	return 1;
	else 
	return 0;
}
