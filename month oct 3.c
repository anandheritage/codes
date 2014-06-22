#include<stdio.h>
#include<stdlib.h>
int found=0,count,n,pass;
int main()
{
    int t,i,j,k,*a,*b,ind;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        a=calloc(n+5,sizeof(int));
        b=calloc(n+5,sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        if(n==1)
        {
            if(a[0]>=b[0])
            {
                pass=1;
                count=a[0]-b[0];
            }
            else
            pass=0;
        }
        while(n>1 && check(a,b)==1)
        {
            count++;
            ind=min(a,b);
            for(i=0;i<n;i++)
            {
                if(i!=ind)
                    a[i]++;
                else
                    a[i]--;
            }
        }
        if(found==1 || (pass==0 && n==1))
            printf("-1\n");
        else
            printf("%d\n",count);
        count=0;
        found=0;
        free(a);
        free(b);
        pass=0;
    }
    return 0;
}
int min(int a[],int b[])
{
    int index_min,mi=10000007,i;
    for(i=0;i<n;i++)
    {
        if((b[i]-a[i])<mi)
        {
            mi=b[i]-a[i];
            index_min=i;
        }
    }
    return index_min;
}
int check(int a[],int b[])
{
    int i;
    found=0;
    for(i=0;i<n;i++)
    {
        if((b[i]-a[i])>0)
            return 1;
        if((b[i]-a[i])<0)
            found=1;
    }
    return 0;
}
