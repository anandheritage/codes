#include<stdio.h>
#include<math.h>
int count,t,n,i,j;
int main(void)
{

    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        for(j=2;j<=sqrt(n);j++)
        {
            if(n%j==0)
            {
                if(check(j))
                    count++;
                if(n/j<=(n/2) && n/j>sqrt(n))
                {
                    if(check(n/j))
                        count++;
                }
            }
        }
        if(check(n))
            count++;
        printf("%d\n",count);
        count=0;
    }
    return 0;

}
int check(int i)
{
    int j,k,n,p;
    n=i;
    for(j=(int)log(i);j>=0;j--)
    {
        k=pow(10,j);
        if(n/k==4 || n/k==7)
        {
            return 1;
        }
        p=n/k;
        k=p*k;
        n=n-k;
    }
    return 0;
}
