#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
vector<int>vec[505];
int cost[505],taken[505];
map<pii,int>mp;

/**http://www.lightoj.com/volume_showproblem.php?problem=1002*/

struct Edge{
    int u,v;
    int w;
    Edge(int uu,int vv, int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};

bool operator<(Edge A , Edge B) {return A.w<B.w;}

int parent[505];

int Find(int x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

void kruskal(int m){

    vector<Edge>E;

    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        parent[u]=u;
        parent[v]=v;
        E.push_back(Edge(u,v,w));
    }

    sort(E.begin(),E.end());
    int sz = E.size();


    for(int i=0 ; i<sz ; i++){
        if(Find(E[i].u) != Find(E[i].v)){
            parent[ parent[E[i].u] ] = parent[ E[i].v ];
            vec[E[i].u].push_back(E[i].v);
            vec[E[i].v].push_back(E[i].u);
            mp[pii(E[i].v,E[i].u)] = E[i].w;
            mp[pii(E[i].u,E[i].v)] = E[i].w;

        }
    }
    //cout<<"kruskal\n";



}

void DFS(int x){

    if(taken[x])return;
    taken[x]=1;

    for(int i=0 ; i<vec[x].size(); i++){
        int k = vec[x][i];
        if(taken[k]==0){
            cost[k] = max(cost[x],mp[pii(k,x)]);
            DFS(k);
        }
    }
}

void solve(int m, int n,int tc){

    kruskal(m);

    memset(cost,0,sizeof(cost));
    memset(taken,0,sizeof(taken));
    scanf("%d",&m);
    DFS(m);

    printf("Case %d:\n",tc);

    for(int i=0 ; i<n ; i++){
        if(cost[i]==0&& i!=m)cout<<"Impossible\n";
        else printf("%d\n",cost[i]);
        vec[i].clear();
    }
    mp.clear();

}

int main()
{

    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++){
        int n,m;
        scanf("%d%d",&n,&m);
        solve(m,n,tc);
    }
    return 0;
}

