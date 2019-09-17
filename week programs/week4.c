/*AIM:c-program to implement dijkstra algorithm
NAME:N.ANAND BABU
ROLL NO:17121A05E1*/
#include<stdio.h>
#include<conio.h>
# define INF 9999
# define MAX 10
void dijkstra(int G[MAX][MAX],int n, int start);
int main()
{
int G[MAX][MAX],i,j,n,u;
printf("enter no: of vertices");
scanf("%d",&n);
printf("entert adj matrix");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("enter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}
void dijkstra(int G[MAX][MAX],int n,int start)
{
int cost[MAX][MAX],dist[MAX],pred[MAX];
int vis[MAX],c,min,next,i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INF;
else
cost[i][j]=G[i][j];
for(i=0;i<n;i++)
{
dist[i]=cost[start][i];
pred[i]=start;
vis[i]=0;
}
dist[start]=0;
vis[start]=1;
c=1;
while(c<n-1)
{
min=INF;
for(i=0;i<n;i++)
if(dist[i]<min && !vis[i])
{
min=dist[i];
next=i;
}
vis[next]=1;
for(i=0;i<n;i++)
if(!vis[i])
if(min+cost[next][i]<dist[i])
{
dist[i]=min+cost[next][i];
pred[i]=next;
}
c++;
}
for(i=0;i<n;i++)
if(!start)
{
printf("dis of node %d=%d",i,dist[i]);
printf("path=%d",i);
j=i;
do{
j=pred[j];
printf("<--%d",j);
}
while(j!=start);
}
}
/*output:
enter the starting node:5
enter no: of vertices5
entert adj matrix
0 4 2 0 8
0 0 0 4 5
0 0 0 1 0
0 0 0 0 3
0 0 0 0 0
enter the starting node:0
dis of node 0=0
path=0<--0
dis of node 1=4
path=1<--0
dis of node 2=2
path=2<--0
dis of node 3=3
path=3<--2<--0
dis of node 4=6
path=4<--3<--2<--0       */

