#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;

void push(int elem)
{
	if(top==MAX-1)
		printf("Stack overflow");
	else
	{
		top=top+1;
		stack[top]=elem;
	}
}

int pop()
{
	int del;
	if(top==-1)
		printf("Stack underflow");
	else
	{
		del=stack[top];
		top=top-1;
		return(del);
	}
}

void display()
{
	int i;
	if(top==-1)
	printf("stack underflow");
	for(i=top;i>=0;i--)
	{
		printf("%d",stack[i]);
	}
}

void palindrome()
{
	int n,flag,i;flag=0;
	printf("enter the number of digits");
	scanf("%d",&n);
	int no[n];
	printf("enter the numbers you want to insert");
	for(i=0;i<n;i++)
	{
		scanf("%d",&no[i]);
		push(no[i]);
	}
	for(i=0;i<n;i++)
	{
		if(pop()!=no[i])
		{	
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("Not a Pallindrome number");
	else
		printf("Pallindrome number");
}


void main()
{
	int ch,elem,del;
	while(1)
	{
		printf("Enter 1 for push, 2 to pop, 3 for palindrome and 4 when you want to display");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element you want to insert");
			scanf("%d",&elem);
			push(elem);
			break;

		case 2:
			del=pop();
			printf("Deleted element is %d",del);
			break;

		case 3:
			palindrome();
			break;

		case 4:
			display();
			break;

		default: printf("Kindly press 1,2,3,4 because that is the only choice you have got");
		}
	}
}
