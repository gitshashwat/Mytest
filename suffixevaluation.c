#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 100
double stack[MAX];
int top=-1;

void push(double elem)
{
	if(top==MAX-1)
		printf("Stack overflow");
	else
	{
		top=top+1;
		stack[top]=elem;
	}
}

double pop()
{
	double del;
	if(top==-1)
		printf("Stack underflow");
	else
	{
		del=stack[top];
		top=top-1;
		return(del);
	}
}
double evaluate(char op, double op1,double op2)
{
switch(op)
{
case '+':
return(op1+op2);
case '*':
return(op1*op2);
case '-':
return(op1-op2);
case '/':
return(op1/op2);
case '%':
return(fmod(op1,op2));
case '^':
return(pow(op1,op2));
default: printf("Invalid operator");
}
}

void main()
{
char suffix[MAX];
int i,val;
double op1,op2,res;
printf("ENter the suffix expression");
scanf("%s",suffix);
for(i=0;suffix[i]!='\0';i++)
{
if(isdigit(suffix[i]))
push(suffix[i]-'0');
if (isalpha(suffix[i]))
{
printf("ENter value of suffix:");
scanf("%d",&val);
push(val);
}
else
{
op2=pop();
op1=pop();
res=evaluate(suffix[i],op1,op2);
push(res);
}
}
res=pop();
printf("\nThe result is %lf", res);
}
