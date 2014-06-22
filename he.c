#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(long long int,long long int,int);
void quicksort(long long int *,long long int,long long int);
long long int partition(long long int *,long long int,long long int);
void merge(long long int *,long long int ,long long int ,long long int );
void merge_sort(long long int *,long long int ,long long int );


int main(void)
{
    long long int t,n,i,j,count=0;
    long long int *a,*b;
    for(scanf("%lld",&t);t>0;t--)
    {
        scanf("%lld",&n);
        a=calloc(n+1,sizeof(long long int));
        b=calloc(n+1,sizeof(long long int));
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
        for(j=1;j<=n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(compare(a[i],b[j],n))
                {
                    count=count+(n-i+1);
                    break;
                }
            }
        }
        printf("%llf\n",(double)(count)/n);
        count=0;
    }
    return 0;
}
int compare(long long int a,long long int b,int n)
{
    if((double)b*log(a)>(double)a*log(b))
        return 1;
    else
        return 0;
}
void merge_sort(long long int a[],long long int p,long long int r)
{
    int q;
        if(p<r)
        {
            q=(p+r)/2;
            merge_sort(a,p,q);
            merge_sort(a,q+1,r);
            merge(a,p,q,r);
        }
}
void merge(long long int a[],long long int p,long long int q,long long int r)
{
    long long int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    long long int l[100000],o[100000];
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
