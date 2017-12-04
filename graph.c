#include<stdio.h>

int n,g[20][20],q[20],visited[20],f=0,r=-1;
void bfs(int c)
{
int i;
for(i=0;i<n;i++)
{
if(!visited[i]&&(g[c][i]==1))
q[++r]=i;
}
if(f<=r)
{
visited[q[f]]=1;
bfs(q[f++]);
}
}

void dfs(int c)
{
int i;
printf("\t%d",c);
visited[c]=1;
for(i=0;i<n;i++)
{
if(!visited[i]&&g[c][i]==1)
dfs(i);
}
}

void main()
{
int ch,i,j,c;
while(1)
{
printf("enter 1 for dfs and 2 for bfs");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("ENter the no of cities");
scanf("%d",&n);
printf("ENter the adjacency matrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&g[i][j]);
}
}

printf("Enter the starting city");
scanf("%d",&c);
for(i=0;i<n;i++)
{
visited[i]=0;
}
printf("\nThe cities searchable are:\n");
dfs(c);
}
break;

case 2:
{
printf("ENter the no of cities");
scanf("%d",&n);
printf("ENter the adjacency matrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&g[i][j]);
}
}

printf("Enter the starting city");
scanf("%d",&c);
for(i=0;i<n;i++)
{
q[i]=0;
visited[i]=0;
}
bfs(c);
printf("\nThe cities searchable are:");
for(i=0;i<n;i++)
{
if(visited[i])
printf("\t%d",i);
}
}
break;

default: printf("Invalid choice");
}
}
}


