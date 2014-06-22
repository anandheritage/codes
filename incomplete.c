#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long int binary_search(long long int * ,long long int ,long long int ,long long int );
long long int merge_sort(long long int * ,long long int ,long long int);
long long int merge(long long int *,long long int ,long long int ,long long int);
long long int uptwo,downtwo,upthree,downthree,t,n,l[100006],o[100006];
main()
{
    long long int *a,*b,count=0,i,kl=0,pl=0,j;
    for(scanf("%lld",&t);t>0;t--)
    {
        scanf("%lld",&n);
        a=calloc(n+5,sizeof(long long int));
        b=calloc(n+5,sizeof(long long int));
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&b[i]);
        }
        merge_sort(a,1,n);
        merge_sort(b,1,n);
        for(i=1;i<=n;i++)
        {
            if(a[i]!=1 && a[i]!=2 && a[i]!=3)
            count=count+binary_search(b,a[i],1,n);
            if(a[i]==2)
            {
                for(j=1;j<=n;j++)
                {
                    if(b[j]==3)
                    count++;
                    if(b[j]>4)
                    break;
                }
                count=count+(n-j+1);
            }
            if(a[i]==3)
            {
                for(j=1;j<=n;j++)
                {
                    if(b[j]==2)
                    count++;
                    if(b[j]>3)
                    break;
                }
                count=count+(n-j+1);
            }
            if(b[i]==1)
                kl++;
            if(a[i]!=1)
                pl++;
        }
        count=count+(kl*pl);
        kl=0;
        pl=0;
        printf("%lf\n",(double)count/n);
        count=0;
    }
    return 0;
}
 long long int binary_search(long long int b[],long long int key,long long int min,long long int max)
{
    long long int mid;
    while(max>=min)
    {
        mid=(min+max)/2;
        if(key>=b[mid])
            min=mid+1;
        else if(key<b[mid])
            max=mid-1;
    }
    return (long long int)(n-mid);
}
long long int merge_sort(long long int a[],long long int p,long long int r)
{
    long long int q;
        if(p<r)
        {
            q=(p+r)/2;
            merge_sort(a,p,q);
            merge_sort(a,q+1,r);
            merge(a,p,q,r);
        }
}
long long int merge(long long int a[],long long int p,long long int q,long long int r)
{
    long long int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    for(i=1;i<=n1;i++)
    {
        l[i]=a[p+i-1];
    }
    for(j=1;j<=n2;j++)
    {
        o[j]=a[q+j];
    }
    l[n1+1]=1000000007;
    o[n2+1]=1000000007;
    i=1;
    j=1;
    for(k=p;k<=r;k++)
    {
        if(l[i]<=o[j])
        a[k]=l[i++];
        else
        a[k]=o[j++];
    }
}


