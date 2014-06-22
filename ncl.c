#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n,i,a[10000],sum1=0,sum2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int first=0,last=n-1;
    for(i=0;i<n;i++)
    {
        if(i&1)
        {
            if(a[first]>a[last])
            {
                sum1=sum1+a[first];
                first++;
            }
            else
            {
                sum1=sum1+a[last];
                last--;
            }
        }
        else
        {
            if(a[first]>a[last])
            {
                sum2=sum2+a[first];
                first++;
            }
            else
            {
                sum2=sum2+a[last];
                last--;
            }
        }
    }
    printf("%d %d\n",sum1,sum2);
    return 0;
}
