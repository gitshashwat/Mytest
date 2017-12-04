#include<stdio.h>
#include<ctype.h>
#define MAX 50
char stack[MAX];
int top=-1;

void push(char elem)
{
	if(top==MAX-1)
		printf("Stack overflow");
	else
	{
		top=top+1;
		stack[top]=elem;
	}
}

char pop()
{
	char del;
	if(top==-1)
		printf("Stack underflow");
	else
	{
		del=stack[top];
		top=top-1;
		return(del);
	}
}

int priority(char c)
{
if(c=='#')
return 0;
if(c=='(')
return 1;
if(c=='+'||c=='-')
return 2;
if(c=='*'||c=='/'||c=='%')
return 3;
if(c=='^')
return 4;
}

void main()
{
char infix[MAX],postfix[MAX];
int i,j;j=0;
printf("Enter the infix expression");
scanf("%s",infix);
push('#');
for(i=0;infix[i]!='\0';i++)
{
if(infix[i]=='(')
push(infix[i]);
else if(isalnum(infix[i]))
	postfix[j++]=infix[i];
else if(infix[i]==')')
{
while(stack[top]!='(')
{
postfix[j++]=pop();
}
top--;
}
else
{
while(priority(stack[top])>=priority(infix[i]))
{
postfix[j++]=pop();
}
push(infix[i]);
}
}
while(stack[top]!='#')
postfix[j++]=pop();
postfix[j]='\0';
printf("POSTFIX EXPRESSION=%s",postfix);
}
