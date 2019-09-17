/*AIM:c-program to compute check sum for the given data stream
NAME:N.ANAND BABU
ROLL NO:17121A05E1*/
#include<stdio.h>
#include<string.h>
int main(){
  char d[100],t[100],k[]="10011",k1[100],q[25],r[25],dt[100];
  int i,j,dlen,klen;
  printf("enter the data stream:");
  scanf("%s",d);
  dlen=strlen(d);
  klen=strlen(k);
  strcpy(k1,k);
  for(i=0;i<klen-1;i++)
      d[dlen+i]='0';
  for(i=0;i<klen;i++)
        t[i]=d[i];
  for(i=0;i<dlen;i++){
    q[i]=t[0];
    if(q[i]=='0')
      for(j=0;j<klen;j++)
        k[j]='0';
    else
      for(j=0;j<klen;j++)
        k[j]=k1[j];
    for(j=klen-1;j>0;j--)
      if(t[j]==k[j])
        r[j-1]='0';
      else
        r[j-1]='1';
    r[klen-1]=d[i+klen];
    strcpy(t,r);
  }
  strcpy(r,t);
  printf("remainder:");
  for(i=0;i<klen-1;i++)
    printf("%c",r[i]);
  printf("\nquotient:");
  for(i=0;i<dlen;i++)
    printf("%c",q[i]);
  printf("\nthe data is:");
  for(i=0;i<dlen;i++)
    dt[i]=d[i];
  for(j=0;j<klen-1;j++)
    dt[i++]=r[j];
  dt[i]='\0';
  printf("%s",dt);
  return 0;
}

/*Input-Output:
enter the data stream:1101011011
remainder:1110
quotient:1100001010
the data is:11010110111110*/
