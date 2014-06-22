#include<stdio.h>
#include<math.h>
int mod(int ,int ,int );
int n,t,i,sum;
int ans;
int main(void)
{
    for(scanf("%lld",&t);t>0;t--)
    {
        scanf("%lld",&n);
        for(i=0;i<=31;i++)
        {
            if(n & 1<<i)
            {
                sum=sum+(int)pow(10,i);
            }
        }
        sum=sum*2;
        ans=mod((int)2,(int)sum,(int)1000000007);
        printf("%d\n",ans);
        sum=0;
    }
    return 0;
}
int mod(int b,int e,int m)
{
int remainder;
int x = 1;
printf("%d\n",e);
while (e != 0)
{
    remainder = e % 2;
    e= e/2;
    if (remainder == 1)
    x = (x * b) % m;
    b= (b * b) % m;
}
printf("%d\n",x);
return (int)x;
}
