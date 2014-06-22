#include<stdio.h>
#include<math.h>
double area(double *,double *,double *,double *,double *,double *);
int main()
{
    int n,i,imax,imin;
    double x1,x2,x3,y3,y1,y2,min=100000000,max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        if(max<=area(&x1,&y1,&x2,&y2,&x3,&y3))
        {
            imax=i;
            max=area(&x1,&y1,&x2,&y2,&x3,&y3);
        }
        if(min>=area(&x1,&y1,&x2,&y2,&x3,&y3))
        {
            imin=i;
            min=area(&x1,&y1,&x2,&y2,&x3,&y3);
        }
    }
    printf("%d %d",imin,imax);
    return 0;
}
double area(double *x1,double *y1,double *x2,double *y2,double *x3,double *y3)
{
    double a=sqrt((*x1-*x2)*(*x1-*x2)+(*y1-*y2)*(*y1-*y2));
    double b=sqrt((*x2-*x3)*(*x2-*x3)+(*y2-*y3)*(*y2-*y3));
    double c=sqrt((*x1-*x3)*(*x1-*x3)+(*y1-*y3)*(*y1-*y3));
    double s=(a+b+c)/2;
    return (sqrt(s*(s-a)*(s-b)*(s-c)));
}
