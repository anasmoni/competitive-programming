#include <bits/stdc++.h>
#define N 100007

using namespace std;
typedef long long int lli;
/**http://www.lightoj.com/volume_showproblem.php?problem=1059*/

vector<int>connect[N];
int taken[N],cnt=0;
int parent[N];
map< pair<int,int> , bool>mp;

void DFS(int x)
{
    if(taken[x])return;
    taken[x]=1;
    for(int i=0 ; i<connect[x].size();i++){
        if(mp[make_pair(x,connect[x][i])])continue;
        if(taken[connect[x][i]]==0)DFS(connect[x][i]);
    }

}

struct Edge{
    int u,v ,w;

    Edge(int uu,int vv, int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};

bool operator<(Edge A , Edge B) {return A.w<B.w;}


int Find(int x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

lli kruskal(int m, int air){

    vector<Edge>E;
    memset(parent,0,sizeof(parent));

    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        parent[u]=u;
        parent[v]=v;
        E.push_back(Edge(u,v,w));
        connect[u].push_back(v);
        connect[v].push_back(u);

    }

    sort(E.begin(),E.end());
    int sz = E.size();
    lli ans=0;

    for(int i=0 ; i<sz ; i++){
        if(Find(E[i].u) != Find(E[i].v)){
            if(air > E[i].w){
                parent[ parent[E[i].u] ] = parent[ E[i].v ];
                ans += E[i].w;
            }
            else {mp[make_pair(E[i].u,E[i].v)]=true;mp[make_pair(E[i].v,E[i].u)]=true;}
        }
    }
    return ans;
}

lli component(int n, int air){

    memset(taken,0,sizeof(taken));

    for(int i=1 ; i<=n ; i++)
    {
        if(taken[i]==0){
            cnt++;
            DFS(i);
        }
    }

    for(int i=1 ; i<=n ; i++)connect[i].clear();
    mp.clear();

    lli res=air*cnt;
    return res;
}

int main(){

    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++){
        int n,m,air;
        cnt=0;
        scanf("%d%d%d",&n,&m,&air);
        lli ans = kruskal(m,air);
        //cout<<ans<<endl;
        ans += component(n,air);
        printf("Case %d: %lld %d\n",tc,ans,cnt);

    }

}
