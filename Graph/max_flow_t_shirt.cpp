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
#define MAXN 20

/***
http://www.lightoj.com/volume_showproblem.php?problem=1176
***/

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

map<string,int>mip;
int  flow[500][500];
int n,m,sink;
int pre[200],cost[200];

void doit()
{
    mip["XXL"] = 1+m;
    mip["XL"] = 2+m;
    mip["L"] = 3+m;
    mip["M"] = 4+m;
    mip["S"] = 5+m;
    mip["XS"] = 6+m;
}



bool bfs()
{

    queue<int> q;
    int u;

    Fill(pre,-1);
    int s=0;
    cost[s] = inf;
    pre[s] = s;
    q.push(s);
    int t = sink;


    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u==t)return true;

        for(int i = 0; i<=sink+8; i++)
        {
            if(pre[i]==-1&&flow[u][i]>0)
            {
                cost[i] = min(cost[u],flow[u][i]);
                pre[i] = u;
                q.push(i);
            }
        }
    }
    return false;
}

int bal()
{
    int maxflow=0;
    int t=sink;

    while(bfs())
    {
        maxflow +=cost[t];
        int u = t;

        while(u!=pre[u])
        {
            flow[pre[u]][u] -=cost[t];
            flow[u][pre[u]] +=cost[t];
            u = pre[u];
        }
    }

    return maxflow;

}

int main()
{

    int t;
    scn(t);


    for(int tc=1; tc<=t; tc++)
    {
        Fill(flow,0);

        scn2(n,m);
        sink=m+7;
        doit();


        string a,b;

        for(int j=1 ; j<=m; j++)
        {

            cin>>a;
            cin>>b;

            int aa=mip[a],bb=mip[b];

            flow[j][aa] = 1;
            flow[j][bb] = 1;

            flow[0][j] = 1;
            flow[0][j] = 1;

            flow[aa][sink] = n;
            flow[bb][sink] = n;


        }
        int oka = bal();

        printf("Case %d: ",tc);

        if(oka>=m)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
