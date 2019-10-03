/*AIM:Write a program to simulate flow based routing.
*/
#include<stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
	    rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
	    for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
            for(k=0;k<nodes;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
		{
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
	    printf("\nFor router %d",i+1);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d Distance %d ",j+1,rt[i].from[j]+1,rt[i].dist[j]);
            }
	}
printf("\nthe path from node 1 to node 2 is congested so it will become 1->3->2 Distance is 6");

}
/*input-output:
Enter the number of nodes : 5

Enter the cost matrix :
0 5 2 3 99
5 0 4 99 3
2 4 0 99 4
3 99 99 0 99
99 3 4 99 0

For router 1
node 1 via 1 Distance 0
node 2 via 2 Distance 5
node 3 via 3 Distance 2
node 4 via 4 Distance 3
node 5 via 3 Distance 6
For router 2
node 1 via 1 Distance 5
node 2 via 2 Distance 0
node 3 via 3 Distance 4
node 4 via 1 Distance 8
node 5 via 5 Distance 3
For router 3
node 1 via 1 Distance 2
node 2 via 2 Distance 4
node 3 via 3 Distance 0
node 4 via 1 Distance 5
node 5 via 5 Distance 4
For router 4
node 1 via 1 Distance 3
node 2 via 1 Distance 8
node 3 via 1 Distance 5
node 4 via 4 Distance 0
node 5 via 1 Distance 9
For router 5
node 1 via 3 Distance 6
node 2 via 2 Distance 3
node 3 via 3 Distance 4
node 4 via 3 Distance 9
node 5 via 5 Distance 0
the path from node 1 to node 2 is congested so it will become 1->3->2 Distance i */
