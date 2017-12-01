#include<stdio.h>
#define MAX 100
int F[MAX],HT[MAX],L;

void display()
{
for(int i=0;i<MAX;i++)
{
printf("%d\t%d\n",i,HT[i]);
}
}

void linear_probing(int k,int key)
{
L=k%MAX;
if(HT[L]==0)
HT[L]=key;
else
linear_probing((k+1),key);
}

void main()
{
int i;i=0;
char buff[1000];
FILE *fp;
fp=fopen("data.txt","r");
while(fscanf(fp,"%d",&F[i])!=EOF)
{
fscanf(fp,"%[^\n]s",buff);
i++;
}

for(i=0;i<MAX;i++)
{
L=F[i]%MAX;
if(HT[L]==0)
HT[L]=F[i];
else
{
linear_probing((F[i]+1),F[i]);
}
}
display();
}

