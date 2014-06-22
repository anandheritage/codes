#include<stdio.h>
#include<stdlib.h>
main()
{
    int *a,*b,x,y,i,t,n,count1=0,count2=0;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        a=calloc(n+1,sizeof(int));
        b=calloc(n+1,sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            count1=count1+func(a,a[i],i);
            count2=count2+func(b,b[i],i);
        }
        printf("%d\n",min(count1,count2));
        count1=0;
        count2=0;
        free(a);
        free(b);
    }
    return 0;
}
int func(int a[],int x,int i)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(a[j]==x)
            return 0;
    }
    return 1;
}
int min(int count1,int count2)
{
    if(count1>count2)
        return count2;
    else
        return count1;
}
