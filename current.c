#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&C[i][j]);
                L[i][j]=B[i][j]-C[i][j];

            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(j!=a[i])
                {
                    if(max<L[i][j])
                    max=L[i][j];
                }
            }
            if(max>B[i][a[i]])
            {
                rel[i]=max;
                profit[i].value=max-B[i][a[i]];
                profit[i].index=i;
            }
            else
            rel[i]=B[i][a[i]];
        }
