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
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define N 2007

int parent[N],n;
/** http://www.lightoj.com/volume_showproblem.php?problem=1123  **/

struct Edge
{
    int u,v;
    int w;
    Edge(int uu,int vv, int ww)
    {
        u=uu;
        v=vv;
        w=ww;
    }
};

bool operator<(Edge A, Edge B)
{
    return A.w<B.w;
}

vector<Edge>E;

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

int kruskal()
{

    sort(atoz(E));
    int sz = E.size();
    int ans=0;
    vector<Edge>V;
    for(int i=1 ; i<=n ; i++)parent[i]=i;

    int cnt=0;

    for(int i=0 ; i<sz ; i++)
    {
        if(Find(E[i].u) != Find(E[i].v))
        {
            parent[ parent[E[i].u] ] = parent[ E[i].v ];
            cnt++;
            ans += E[i].w;
            V.pb(Edge(E[i].u,E[i].v,E[i].w) ) ;
            if(cnt==n-1)break; /**i found mst so quit**/
        }
    }

    if(cnt!=n-1)return -1;
    E = V;  /**main thing of this problem.....i put edges of mst only with newly coming edge
    then E size will b n....here n=200.....so...**/
    return ans;

}

int main()
{

    int t;
    scanf("%d",&t);
    for(int tc=1,m; tc<=t ; tc++)
    {
        scn2(n,m);
        printf("Case %d:\n",tc);
        E.clear();


        for(int i=1; i<=m ; i++)
        {
            int u,v,w;
            scn3(u,v,w);
            E.pb(Edge(u,v,w));
            if(i<n-1)printf("-1\n");
            else printf("%d\n",kruskal());
        }

    }

}
