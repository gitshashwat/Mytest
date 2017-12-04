#include<stdio.h>
#define MAX 5
int f=-1,r=-1;
char q[MAX];

void insert()
{
char elem;
printf("Enter the element you want to enter\n");
scanf("\n%c",&elem);
if((f==0)&&(r==MAX-1)||(f==r+1))
{
printf("Queue overflow\n");
return;
}
if(f==-1)
{
f=0;
}
r=(r+1)%MAX;
q[r]=elem;

}

void display()
{
int i;
if(f==-1)
printf("Queue underflow");
printf("The elements of Queue are");
for(i=f;i!=r;i=(i+1)%MAX)
printf("\t%c",q[i]);
printf("\t%c\n",q[i]);
}

void delete()
{
if(f==-1)
printf("queue underflow\n");
printf("The deleted element is %c\n",q[f]);
if(f==r)
{
f=-1;
r=-1;
}
else
f=(f+1)%MAX;
}

void main()
{
int ch;
while(1)
{
printf("Enter 1 for insertion, 2 for deletion and 3 for display\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
default: printf("Invalid choice\n");
}
}
}


