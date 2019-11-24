#include<bits/stdc++.h>
using namespace std;

#define  INF 2e18

typedef long long ll;
typedef pair<ll,int> ii;
/** http://codeforces.com/problemset/problem/20/C .......see shafayet blog also*/
int n,m,p[100005];
vector<ii> g[100005];
ll d[100005];
int vis[100005];

void trace(int k)
{
    if(p[k]!=-1) trace(p[k]) ;
    cout<<k<<" ";
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int u,v,l;
        cin>>u>>v>>l;
        g[u].push_back(ii(v,l));
        g[v].push_back(ii(u,l));
    }
    fill(p,p+n+5,-1);
    fill(d,d+n+5,INF);
    d[1] = 0;
    set<ii >s;
    int u;
    s.insert(ii(d[1],1));
    while(!s.empty())
    {
        u = s.begin()->second;
        s.erase(s.begin());
        for(int i=0; i<g[u].size(); i++)
        {
            if(d[g[u][i].first]>d[u]+g[u][i].second)
            {
                d[g[u][i].first]= d[u]+g[u][i].second;
                p[g[u][i].first] = u;

                s.insert(ii(d[g[u][i].first],g[u][i].first));
            }
        }

    }
    vector<int>::iterator it;
    if(d[n]==INF)
        cout<<-1<<endl;
    else
    {
        trace(n);
    }
}
