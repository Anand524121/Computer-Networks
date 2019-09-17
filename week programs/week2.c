/*AIM:c-program to implement frame sorting
NAME:N.ANAND BABU
ROLL NO:17121A05E1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frame
{

    int sno;
    char msg[15];
    int flag;

};
int main()
{
    int i,j,n,r,k;
    printf("enter no of frames\n");
    scanf("%d",&n);
    struct frame fr[n];
    int s[n];
    for(i=0;i<n;i++)
    {
        s[i]=-1;
        fr[i].sno=-1;
    }


    printf("enter the message \n");
    for(i=0;i<n;i++)
    {
        scanf("%s",fr[i].msg);
        fr[i].sno=i;
    }
     for(j=0;j<n;j++)
    {

        r=rand()%n;
        if(s[r]==-1)
        {
            fr[j].flag=r;
            s[r]=1;
        }
        else if(s[r]==1)
        {
            for(k=0;k<n;k++){
                r=k;
                if(s[r]==-1)
        {
            fr[j].flag=r;
            s[r]=1;
            break;
        }
            }
        }
    }

        printf("arrived frame are:\n");
        printf("\n sno \t msg  \n");
        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                if(fr[j].flag==i)
                {
                      printf("%d\t%s",fr[j].sno,fr[j].msg);
                printf("\n");
                }

            }

            for(i=0;i<n;i++)
            {
                for(j=0;j<n-1;j++)
                {
                    if(fr[j].sno>fr[j+1].sno)
                    {
                        struct frame temp;
                        temp=fr[j];
                        fr[j]=fr[j+1];
                        fr[j+1]=temp;
                    }
                }
            }



            printf("after sorting arrived frames are\n");
              printf("\n sno \t msg \n");
        for(i=0;i<n;i++)
            {
                printf("%d\t%s",fr[i].sno,fr[i].msg);
                printf("\n");
            }
            return 0;


    }
/*INPUT-OUTPUT:
enter no of frames
3
enter the message
678
546
324
arrived frame are:

 sno     msg
1       546
0       678
2       324
after sorting arrived frames are

 sno     msg
0       678
1       546
2       324
678546324   */