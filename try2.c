#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int modulo(  long long int,  long long int,  long long int);
long long int mulmod( long long int, long long int, long long int);
long long int isPrime[10000000],prime[10000000];

int perfectsquare(long long int a)
{
    long long int b;
    b=sqrt(a);
    if(b*b==a)
    return 1;
    else
    return 0;
}

int main(void)
{
    long long int i,j,k=0,t,n,count=0,counter=0,a1,b,l;
    for(i=2;i<=1000000;i++)
    {
        if(isPrime[i]==0)
        {
            prime[k++]=i;
            for(j=i;i*j<=1000000;j++)
            {
                isPrime[i*j]=1;
            }
        }
    }
    for(scanf("%lld",&t);t>0;t--)
    {
        scanf("%lld %lld",&a1,&b);
        for(l=a1;l<=b;l++)
        {
            if(perfectsquare(l));
            else
            continue;
            i=l;
            for(j=0;prime[j]<=sqrt(i);j++)
            {
                if(i%prime[j]==0)
                {
                    while(i%(prime[j]*prime[j])==0)
                    {
                        count=count+2;
                        i=(long long int)i/(prime[j]*prime[j]);
                    }
                    if(i%prime[j]==0)
                    {
                        count++;
                        i=i/prime[j];
                    }
                    break;
                }
            }
            if(i==l && l!=1)
            {
                counter++;
            }
            if(i==1 && l!=1)
            {
                count++;
                if(isPrime[count]==0)
                {
                    counter++;
                }
            }
            count=0;
        }
        printf("%lld\n",counter);
        counter=0;
    }
}

