#include<stdio.h>
#include<stdlib.h>
int t,n,i,j,k,l,count=0,c1,c2;
char st[510][540];
int main(void)
{
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d%d%d%d",&k,&l,&c1,&c2);
        for(i=1;i<=k;i++)
        {
            scanf("%s",st[i]);
        }
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=l;j++)
            {
                if(st[i][j]=='W')
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
        count=0;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=l;j++)
            {
                if(st[i][j]=='W')
                    printf("2 %d %d\n",i,j);
            }
        }
    }
    return 0;
}
