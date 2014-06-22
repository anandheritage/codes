#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct data
{
	int first;
	int final;
	int last;
};
struct data store[1000001];
int n,k,visit[1000001],a[1000001],found=0,i,j,mina=1000001,first_index,second_index;
int main(void)
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(visit[a[i]]==0)
		store[a[i]].first=i;
		store[a[i]].last=i;
		visit[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(store[a[i]].last>(n/2))
		store[a[i]].last=n-store[a[i]].last+1;
		if(store[a[i]].first>(n/2))
		store[a[i]].first=n-store[a[i]].first+1;
		if(store[a[i]].last<store[a[i]].first)
		store[a[i]].final=store[a[i]].last;
		else
		store[a[i]].final=store[a[i]].first;
	}
	int temp=k;
	for(i=1;i<=n;i++)
	{
		if(k>a[i])
		{

			temp=k-a[i];
			if(visit[temp]==1 && temp!=a[i] && temp!=0)
			{
				found=1;
				//printf("%d(%d)  %d(%d)\n",store[a[i]].final,a[i],store[temp].final,temp);
				int maxx=max(store[a[i]].final,store[temp].final);
				if(maxx<mina)
				mina=maxx;
			}
		}
	}
	if(found)
	printf("%d\n",mina);
	else
	printf("-1\n");
	return 0;
}
