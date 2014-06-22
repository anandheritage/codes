#include<stdio.h>
#include<stdlib.h>
int found,t,n,i,j,k;
int main(void)
{
    int **table,*sum;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d %d",&n,&k);
        table=calloc(n+1,sizeof(int *));
        sum=calloc(k+1,sizeof(int));
        for(i=0;i<=n;i++)
            table[i]=calloc(k+1,sizeof(int));
        for(i=0;i<=n;i++)
        {
            for(j=0;j<k;j++)
            {
                scanf("%d",&table[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            found=0;
            for(j=0;j<k;j++)
            {
                sum[j]=sum[j]+table[i][j];
            }
            for(j=0;j<k;j++)
            {
                if(sum[j]<table[n][j])
                found=1;
            }
            if(found==0)
            break;
        }
        if(found==0)
        {
            printf("%d\n",i+1);
            for(j=1;j<=i;j++)
                printf("%d ",j);
            printf("%d",i+1);
        }
        else
        printf("0");
        printf("\n");
        for(i=0;i<=n;i++)
        {
            free(table[i]);
        }
        free(sum);
    }
    return 0;

}




