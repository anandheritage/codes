#include<stdio.h>
#include<stdlib.h>
int t,n,i,j,k,l,count=0,c1,c2,count2=0;
char st[510][540];
int main(void)
{
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d%d%d%d",&k,&l,&c1,&c2);
        for(i=0;i<k;i++)
        {
            scanf("%s",st[i]);
        }
        for(i=0;i<k;i++)
        {
            for(j=0;j<l;j++)
            {
                if(st[i][j]=='B')
                {
                    count++;
                }
                if(st[i][j]=='W')
                count2++;
            }
        }
        if((c1*count2)>(c2*count))
        {
            printf("%d\n",count);
            for(i=0;i<k;i++)
            {
                for(j=0;j<l;j++)
                {
                    if(st[i][j]=='B')
                        printf("3 %d %d\n",i+1,j+1);
                }
            }
        }
        else
        {
            printf("%d\n",count2);
            for(i=0;i<k;i++)
            {
                for(j=0;j<l;j++)
                {
                    if(st[i][j]=='W')
                        printf("2 %d %d\n",i+1,j+1);
                }
            }
        }
        count=count2=0;
    }

    return 0;
}
