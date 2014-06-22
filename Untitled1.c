#include<stdio.h>
#include<string.h>
char st[2000][2000];
int count,start,finish,n,m,i,j,found,kt[2000];
int main(void)
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s",st[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(st[i][j]=='G')
            start=j;
            else if(st[i][j]=='S')
            finish=j;
        }
        if(finish-start>0)
        kt[finish-start]=1;
        else
        {
            found=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(kt[i]==1)
        count++;
    }
    if(found)
    printf("-1\n");
    else
    printf("%d\n",count);
    return 0;
}
