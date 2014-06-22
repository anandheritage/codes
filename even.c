#include<stdio.h>
#include<math.h>
int n,t,k,i,sum;
int main(void)
{
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        for(i=31;i>=0;i--)
        {
            if(n & 1<<i)
            {

                sum=sum+pow(2,k);
                k++;
            }
            else if(k!=0)
                k++;
        }
        if(n==4294967296)
        printf("1\n");
        else
        printf("%d\n",sum);
        sum=k=0;
    }
    return 0;
}
