#include<stdio.h>
#include<math.h>
long long int Prime[1000009],isPrime[1000009],count,a,b,t;
long long int modulo(  long long int,  long long int,  long long int);
long long int mulmod( long long int, long long int, long long int);

int main(void)
{
    long long int i,j,k=0;
    for(i=2;i<=1000000;i++)
    {
        if(isPrime[i]==0)
        {
            Prime[k++]=i;
            for(j=i;(long long int)(i*j)<=(long long int)1000000;j++)
            {

                isPrime[(i*j)]=1;
            }
        }

    }
    for(scanf("%lld",&t);t>0;t--)
    {
        scanf("%lld %lld",&a,&b);
        if(a==1)
        a=2;
        for(i=2;(long long int )i<=(long long int)b && a!=1 && b!=1;i++)
        {
            if(i<=1000000)
            {
                if(isPrime[i]==0)
                {
                    //printf("%lld %lld\n",(long long int )pow(i,Prime[0]-1),(long long int)pow(i,Prime[2]-1));
                    for(j=0;(long long int)pow(i,Prime[j]-1)<=(long long int)b;j++)
                    {
                        if((long long int)pow(i,Prime[j]-1)>=(long long int)a)
                        count++;
                    }
                }
            }
            else
            {
                if(Miller((long long int)i,(long long int)2) && i>=a)
                count++;
            }
        }
        printf("%lld\n",count);
        count=0;
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
