#include<iostream>
#include<algorithm>
using namespace std;
struct log {
       int sd;
       int ed;
} loga[1000];
bool key(const log & i,const log & j) {
 return (i.ed > j.ed);
}
int main() {
int n,i;
cin>>n;
for (i=0;i<n;i++) cin>>loga[i].sd>>loga[i].ed;
sort(loga,loga+n,key);
for (i=0;i<n;i++) cout<<loga[i].sd<<","<<loga[i].ed<<endl;
system("PAUSE");
}
