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
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define N 50003

int parent[N],vis[N],Tree[N],Level[N];
pii Anc[N][17];

/**http://lightoj.com/volume_showproblem.php?problem=1101**/

struct Edge{
    int u,v,w;
    Edge(int uu,int vv, int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};

vector<Edge>E;
vector<int>mst[N];
map<pii,int>Dan;

bool operator<(Edge A , Edge B) {return A.w<B.w;}

int Find(int x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

void kruskal(){

    sort(E.begin(),E.end());

    for(int i=0 ; i<E.size() ; i++){

        if(Find(E[i].u) != Find(E[i].v)){

            parent[ parent[E[i].u] ] = parent[ E[i].v ];

            mst[E[i].u].pb(E[i].v);
            mst[E[i].v].pb(E[i].u);

            Dan[pii(E[i].u,E[i].v)] = E[i].w;
            Dan[pii(E[i].v,E[i].u)] = E[i].w;
        }
    }
}

void bfs(int x){

    queue<int>q;
    q.push(x);
    vis[x]=1;
    Level[x]=0;

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int i=0; i<mst[u].size(); i++){

            int v = mst[u][i];

            if(vis[v]==0){
                vis[v]=1;
                Tree[v]=u;
                q.push(v);
                Level[v] = 1+Level[u];
            }
        }
    }
}

void LCA(int n){

    for(int i=1; i<=n; i++) {
        Anc[i][0] = pii(Tree[i], Dan[pii(i,Tree[i])] );
    }

    for(int j=1; 1<<j <= n; j++){

        for(int i=1; i<=n; i++){

            if(Anc[i][j-1].fi != -1){

                Anc[i][j].fi = Anc[ Anc[i][j-1].fi ][j-1].fi;

                Anc[i][j].se = max(Anc[i][j-1].se, Anc[ Anc[i][j-1].fi ][j-1].se);

            }
        }
    }
}


void init(int n){

    E.clear();
    Dan.clear();

    for(int i=1; i<=n; i++){
        parent[i]=i;
        Tree[i] = -1;
        vis[i]=0;
        mst[i].clear();
        Level[i]=0;

        for(int j=0; 1<<j <= N; j++){
            Anc[i][j] = pii(-1,-1);
        }
    }
}

int solve(int x,int y){

    int ans=-1, kth;

    if(Level[x]<Level[y])swap(x,y);

    for(kth = 1; 1<<kth <= Level[x]; kth++);
    kth--;

    for(int i=kth ; i>=0; i--){
        if(Level[x]-(1<<i) >= Level[y]){
            ans = max(ans, Anc[x][i].se);
            x = Anc[x][i].fi;
        }
    }

    if(x==y)return ans;

    for(int i=kth; i>=0; i--){

        if(Anc[x][i].fi != -1 && Anc[x][i].fi != Anc[y][i].fi){

            ans = max(ans, Anc[x][i].se);
            x = Anc[x][i].fi;
            ans = max(ans, Anc[y][i].se);
            y = Anc[y][i].fi;
        }
    }


    ans = max3(ans, Dan[ pii(x,Tree[x])], Dan[ pii(y,Tree[y]) ] );

    return ans;
}

int main(){

    int t;
    scanf("%d",&t);

    for(int tc=1 ; tc<=t ; tc++){

        int n,m;
        scn2(n,m);

        init(n);

        for(int u,v,w; m ; m--){

            scn3(u,v,w);
            E.pb(Edge(u,v,w));
        }

        kruskal();
        bfs(E[0].u);
        LCA(n);
        printf("Case %d:\n",tc);
        int q;
        scn(q);

        for(int x,y; q;q--){
            scn2(x,y);
            printf("%d\n",solve(x,y));
        }


    }

}

