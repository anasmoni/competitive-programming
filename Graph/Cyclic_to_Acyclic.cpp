#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define N 505

int vis[N] , cnt=0;
vector<int>V[N];

void dfs(int x){

    vis[x]=1;

    for(auto u : V[x]){
        if(vis[u]==0)dfs(u);
        else if(vis[u]==1)cnt++;
    }
    vis[x]=2;
}

/// http://codeforces.com/problemset/problem/915/D
/// Given a dir graph G .....is it possible to make G acyclic removing atmost one edge
/// number of edges <= 1e5

int main(){

    int n,m;
    scn2(n,m);

    while(m--){
        int x,y;
        scn2(x,y);
        V[x].pb(y);
    }
    ///check if there exist an edge E , that is in every cycle.......or their is no cycle

    for(int i=1; i<=n; i++){
        Fill(vis,0);
        cnt=0;
        dfs(i); /// if edge E contains vertex i........so dfs(i) will visit all cycles

        for(int k=1; k<=n; k++){ /// check if their is any cycle still exist which doesn't contain E
            if(!vis[k])dfs(k);
        }
        if(cnt<=1){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
