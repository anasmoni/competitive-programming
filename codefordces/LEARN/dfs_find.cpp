#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+7;
int n,m,num[maxn],f[maxn];
priority_queue<int> q[maxn];

int find(int x){
	return f[x]==x?x:(f[x]=find(f[x])); /** look */
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){scanf("%d",&num[i]);f[i]=i;}

	for(int i=1;i<=m;++i){
		int u,v;scanf("%d%d",&u,&v);
		int p1=find(u),p2=find(v);
		f[p1]=p2;
		cout<<"p1 p2 "<<p1<<" "<<p2<<endl;
	}

	//for(int i=1 ; i<=n;cout<<f[i++]<<" ");
	//cout<<endl;

	for(int i=1;i<=n;++i)find(i);

	//for(int i=1 ; i<=n ; i++)cout<<f[i]<<" ";
	//cout<<endl;

	for(int i=1;i<=n;++i)q[f[i]].push(num[i]);

	for(int i=1;i<=n;++i)num[i]=q[f[i]].top(),q[f[i]].pop();

	for(int i=1;i<=n;++i)printf("%d%c",num[i],i==n?'\n':' '); /** look */
}
