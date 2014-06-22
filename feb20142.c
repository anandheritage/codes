#include<stdio.h>
#include<stdlib.h>
int a[100];
int n,i,j,k,q,save1,save2;
int main(void)
{

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(scanf("%d",&q);q>0;q--)
    {
        scanf("%d",&k);
        int sum=0,j=1;
        for(i=1;i<=n;i++)
        {
            if(k==a[i])
            {
                for(j=i-1;j>0;j--)
                {
                    if(a[j]<=k)
                    break;
                }
                save1=j;
                for(j=i+1;j<=n;j++)
                {
                    if(a[j]<k)
                    break;
                }
                save2=j;
                sum=sum+(i-save1-1)*(save2-i)+(save2-i);
                //printf("%d\n",save1-i);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
