#include<stdio.h>
void tower_hanoi(int n,char src,char temp,char dest)
{
if (n==1)
{
printf("\nMove disk %d from %c to %c",n,src,dest);
return;
}
tower_hanoi(n-1,src,dest,temp);
printf("\nMove disk %d from %c to %c",n,src,dest);
tower_hanoi(n-1,temp,src,dest);
}

int main()
{
int n;
printf("Enter the no. of discs");
scanf("%d",&n);
tower_hanoi(n,'A','B','C');
}
