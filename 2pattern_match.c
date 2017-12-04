#include<stdio.h>

char str[20],pat[20],rep[20];
int str_len,pat_len,rep_len;

void read()
{
int i;
printf("Enter the main string");
scanf("%s",str);
printf("Enter the pattern string");
scanf("%s",pat);
printf("Enter the replacement string");
scanf("%s",rep);

for(i=0;str[i]!='\0';i++)
{
str_len++;
}
for(i=0;pat[i]!='\0';i++)
{
pat_len++;
}
for(i=0;rep[i]!='\0';i++)
{
rep_len++;
}
}

void pattern_match()
{
int i,j,flag;flag=0;
for(i=0;i<str_len;i++)
{
j=0;
while((str[i+j]==pat[j])&&(j<pat_len))
j++;
if(j==pat_len)
{
flag=1;
for(j=0;j<rep_len;j++)
{
str[i+j]=rep[j];
}
i=i+pat_len-1;
}
}
if(flag==0)
printf("pattern not found");
else
printf("String after replacement:%s",str);
}
void main()
{
read();
pattern_match();
}
