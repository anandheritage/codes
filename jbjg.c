#include<stdio.h>
#include<stdlib.h>
int sum,a[1000000],n,k[1000000],i,max;
int main(void)
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        k[a[i]]++;
        if(a[i]>max)
        max=a[i];
    }
    for(i=1;i<max;i++)
    {
        if(k[i]>=2 )
        sum=sum+2;
        else if(k[i]==1)
        sum=sum+1;
    }
    sum++;
    printf("%d\n",sum);

    for(i=1;i<=max;i++)
    {
        if(k[i]>0)
        {
            printf("%d ",i);
            k[i]--;
        }
    }
    for(i=max-1;i>=1;i--)
    {
        if(k[i]>0)
        {
            printf("%d ",i);
            k[i]--;
        }
    }
    return 0;
}
