#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct data
{
    int value;
    int index;
};
bool key(const data & i,const data  & j) {
 return (i.value > j.value);
}
struct data diff[1001];
int L[1001][1001],B[1001][1001],C[1001][1001];
int a[1001],rel[1001];
int main(void)
{
    int t,n,m,k,maxi=0,i,j;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&C[i][j]);
                L[i][j]=B[i][j]-C[i][j];
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(j!=a[i])
                {
                    if(maxi<L[i][j])
                    maxi=L[i][j];
                }
            }
            if(maxi>L[i][a[i]])
            {
                diff[i].value=maxi-L[i][a[i]];
                rel[i]=maxi;
                diff[i].index=i;
            }
            else
                rel[i]=L[i][a[i]];
        }
        sort(diff+1, diff+n+1,key);
        for(i=1;i<=k;i++)
        {
            if(diff[i].value>0)
            {
                a[diff[i].index]=rel[diff[i].index];
                printf("gg");
            }
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+B[i][a[i]];
            printf("%d\n",a[i]);
        }
        printf("%d\n",sum);
    }
}






