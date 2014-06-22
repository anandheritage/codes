#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char st[100];
long long int found,product=1,i,n,hell;
int main(void)
{
    scanf("%I64d",&n);
    scanf("%s",st);
    for(i=0;i<n;i++)
    {
        if(st[i]=='B')
        hell++;
    }
    if(hell>=n-1)
    {
        count=pow(2,n)-1;
        printf("%I64d\n",count);
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(st[i]=='B')
        {
            found=1;
            product=product*(i+1);
        }
    }
    if(found)
    printf("%I64d\n",product);
    else
    printf("0\n");
    return 0;
}
