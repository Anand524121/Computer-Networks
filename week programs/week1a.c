/*AIM:c-program to implement character counting
NAME:N.ANAND BABU
ROLL NO:17121A05E1*/
#include<stdio.h>
int main()
{
 int f[10],arr[100];
 int a=0,n,sum1=0,sum=0,i,j;
 printf("Enter the size of the frame\n");
 scanf("%d",&n);
printf("Enter the frame numbers other than 0's\n");
 for(i=0;i<n;i++)
{
 scanf("%d",&f[i]);
}
printf("Enter the data values\n");
for(i=0;i<n;i++)
{
 arr[a]=f[i];
 sum=sum+f[i];
for(j=a+1;j<sum;j++)
{
 scanf("%d",&arr[j]);
}
a=j;
}
for(i=0;i<n;i++)
{
 sum1=sum1+f[i];
}
printf("after character stuffing\n");
for(i=0;i<sum1;i++)
{
 printf("%d",arr[i]);
}
}
/*INPUT-OUTPUT
Enter the size of the frame
4
Enter the frame numbers other than 0's
3
6
5
3
Enter the data values
2
1
3
2
3
4
5
6
5
4
3
4
5
after character stuffing
32163234556543345*/