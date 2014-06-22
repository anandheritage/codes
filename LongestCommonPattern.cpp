#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void)
{
    char st1[10001],st2[10001];
    int t,st1_len,st2_len;

    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%s",st1);
        scanf("%s",st2);
        st1_len=strlen(st1);
        st2_len=strlen(st2);
        sort(st1,st1+st1_len);
        sort(st2,st2+st2_len);
        int first=0,second=0,count=0;
        while(1)
        {
            if(!(first<st1_len && second<st2_len))
            {
                break;
            }

            if(st1[first]<st2[second])
            first++;
            else if(st1[first]>st2[second])
            second++;
            else
            {
                count++;
                first++;
                second++;
            }

        }
        printf("%d\n",count);
    }
    return 0;
}
