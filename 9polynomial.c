#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial
{
int coef,x,y,z;
struct polynomial *link;
};
typedef struct polynomial *poly;

poly create()
{
poly getnode;
getnode=(poly)malloc(sizeof(struct polynomial));
if(getnode==NULL)
{
printf("\nMemory not allocated\n");
return(getnode);
}
return(getnode);
}

poly insert_end(poly head, int c, int px, int py, int pz)
{
poly node,temp;
node=create();
node->coef=c;
node->x=px;
node->y=py;
node->z=pz;
node->link=NULL;
temp=head->link;
while(temp->link!=head)
{
temp=temp->link;
}
temp->link=node;
node->link=head;
return(head);
}

poly input_polynomial(poly head)
{
int i,c,px,py,pz;
printf("Enter 999 to end polynomial\n");
while(1)
{
printf("Enter the coefficient\n");
scanf("%d",&c);
if(c==999)
break;
printf("Enter power of x,y and z\n");
scanf("%d%d%d",&px,&py,&pz);
head=insert_end(head,c,px,py,pz);
}
return head;
}

void display(poly head)
{
poly temp;
if(head->link==head)
{
printf("NO Polynomial");
return;
}
temp=head->link;
while(temp!=head)
{
printf("%dx^%dy^%dz^%d+",temp->coef,temp->x,temp->y,temp->z);
temp=temp->link;
}
printf("999\n");
}

poly sum(poly head1, poly head2, poly head3)
{
poly p1,p2;
int flag;
p1=head1->link;
while(p1!=head1)
{
p2=head2->link;
flag=0;
while(p2!=head2)
{
if((p1->x==p2->x)&&(p1->y==p2->y)&&(p1->z==p2->y))
{
head3=insert_end(head3, p1->coef+p2->coef,p1->x,p1->y,p1->z);
p2->coef=0;
flag=1;
break;
}
p2=p2->link;
}
if(flag==0)
head3=insert_end(head3,p1->coef,p1->x,p1->y,p1->z);
p1=p1->link;
}
p2=head2->link;
while(p2!=head2)
{
if(p2->coef!=0)
head3=insert_end(head3,p2->coef,p2->x,p2->y,p2->z);
p2=p2->link;
}
return head3;
}

int evaluate_polynomial(poly head)
{
int vx,vy,vz,sum=0;
poly temp;
printf("Enter the value of x,y and z\n");
scanf("%d%d%d",&vx,&vy,&vz);
temp=head->link;
while(temp!=head)
{
sum=sum+(temp->coef*pow(vx,temp->x)*pow(vy,temp->y)*pow(vz,temp->z));
temp=temp->link;
}
return(sum);
}

void main()
{
int ch;
while(1)
{
printf("Enter 1 to evaluate a polynomial and 2 to find the sum of two polynomials\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
poly head;
int res;
head=create();
head->link=head;
printf("enter the polynomial to be evaluated\n");
head=input_polynomial(head);
printf("\nThe given polynomial is:");
display(head);
res=evaluate_polynomial(head);
printf("\nThe result after evaluation is:%d\n",res);
}
break;
case 2:
{
poly head1,head2,head3;
head1=create();
head1->link=head1;

head2=create();
head2->link=head2;

head3=create();
head3->link=head3;

printf("Enter the polynomial\n");
head1=input_polynomial(head1);
display(head1);

printf("Enter the second polynomial\n");
head2=input_polynomial(head2);
display(head2);

head3=sum(head1,head2,head3);
printf("\nsum of two polynomials is\n");
display(head3);
}
break;
default: printf("Stop pressing random numbers kid\n");
}
}
}
