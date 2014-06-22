#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char st[100];
long long int found,count,i,n,hell;
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
        count=(long long int)pow(2,n)-1;
        printf("%I64d\n",count);
        return 0;
    }
    while(1)
    {
        while(st[i]=='R')
        {
            i++;
            if(i==n-1)
            {
                found=1;
                break;
            }
        }
        if(found)
        break;
        st[i]='R';
        while(i>0)
        {
            i--;
            st[i]='B';
        }
        count++;
    }
    printf("%I64d\n",count);
    return 0;
}
