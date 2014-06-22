#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000],x,i,j,k,n,t,k,taller[2000];
int main(void)
{
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&taller[i]);
        }
        quicksort(a,0,n-1);
        for(i=1;i<n;i++)
        {
            x=a[i];
            j=i-1;
            k=0;
            while(k<(i-taller[i]))
            {
              a[j+1]=a[j];
                j--;
                k++;
            }
            a[j+1]=x;
        }
        for(i=0;i<n-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[i]);


    }
}
quicksort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
partition(int a[],int p,int r)
{
    int x,i,j,t;
    i=p-1;
    x=a[r];
    for(j=p;j<r;j++)
    {
        if(a[j]>x)
        {
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            t=taller[i];
            taller[i]=taller[j];
            taller[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    t=taller[i+1];
    taller[i+1]=taller[r];
    taller[r]=t;
    return i+1;
}
