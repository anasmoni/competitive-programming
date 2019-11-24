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
#define N 100005

vector<int>RV[107];
int parent[107];
int cap[107][107];
/**undirected
http://www.lightoj.com/volume_showproblem.php?problem=1153**/
/**  O(V*E*E)  ***/


bool bfs(int s, int t)
{

    queue <int> q;
    q.push(s);
    Fill(parent,0);
    parent[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<RV[u].size(); i++){ ///vector suck
            int v = RV[u][i];

            if(!parent[v] && cap[u][v]>0){
                q.push(v);
                parent[v] = u;
            }
        }
    }
    return parent[t];
}

int fordFulkerson(int s, int t,int vx)
{
    int u, v;

    int max_flow = 0;

    while (bfs(s,t))
    {

        int path_flow = INT_MAX;

        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, cap[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            cap[u][v] -= path_flow;
            cap[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int t;
    scn(t);

    for(int tc=1; tc<=t; tc++){

        int vx,src,sink,edges;
        scn(vx);
        Fill(cap,0);
        scn3(src,sink,edges);

        while(edges--){

            int u,v,c;
            scn3(u,v,c);

            RV[u].pb(v);
            cap[u][v]+=c; /**as bidirectional***/
            RV[v].pb(u);
            cap[v][u]+=c;
        }

        printf("Case %d: %d\n",tc,fordFulkerson(src,sink,vx));

        for(int i=1; i<=vx; i++) RV[i].clear();


    }


    return 0;
}
