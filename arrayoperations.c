#include<stdio.h>

int n;

void create(int a[])
{
	int i;
	printf("enter the elements of the array because this is how you create it");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void display(int a[])
{
	int i;
	for(i=0;i<n;i++)
	printf("%d",a[i]);
}

int insert(int a[])
{
	int i,pos,key;
	printf("enter the position and key where you want to insert");
	scanf("%d%d",&pos,&key); 
	for(i=n-1;i>=(pos-1);i--)
	{
		a[i+1]=a[i];
	}
	a[pos-1]=key;
	n++;
	return(n);
}

int delete(int a[])
{
	int i,pos;
	printf("Enter the position where you want to delete");
	scanf("%d",&pos);
	for(i=pos-1;i<(n-1);i++)
	{
		a[i]=a[i+1];
	}
	--n;
	return(n);
}



void main()
{
	int ch;
	printf("enter the size of your array");
	scanf("%d",&n);
	int a[n];
	while(1)
	{
		printf("Enter 1 for create,2 for insert, 3 for delete and 4 for display");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create(a);
			break;

			case 2:
			n=insert(a);
			break;

			case 3:
			n= delete(a);
			break;

			case 4:
			display(a);
			break;

			default: printf("Stop pressing whatever number you want to");
		}
	}	
}

