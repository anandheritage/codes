#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int modulo(  long long int,  long long int,  long long int);
long long int mulmod( long long int, long long int, long long int);
long long int isPrime[10000000],prime[10000000];
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
                    break;
                }
            }
            if(i==l && l!=1)
            {
                printf("%lld\n",l);
                counter++;
            }
            if(i==1 && l!=1)
            {
                count++;
                if(Miller((long long int)(count),(long long int)1))
                {
                    counter++;
                    printf("%lld\n",l);
                }
            }
            count=0;
        }

        printf("%lld\n",counter);
        counter=0;
    }

    return 0;
}
int Miller(  long long int p,  long long int iteration)
{
      long long int i;
    if(p<2)
    {
        return 0;
    }
    if(p!=2 && p%2==0)
    {
        return 0;
    }
      long long int s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(i=0;i<iteration;i++)
    {
          long long int a=rand()%(p-1)+1,temp=s;
          long long int mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
        {
            return 0;
        }
    }
    return 1;
}
  long long int modulo(  long long int a,  long long int b,  long long int c)
 {
      long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c);
        b /= 2;
    }
    return x%c;
}
 long long int mulmod( long long int a, long long int b,  long long int c)
{
         long long int x = 0,y=a%c;
        while(b > 0){
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
