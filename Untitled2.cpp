#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int a[100];
int main(void)
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
}
