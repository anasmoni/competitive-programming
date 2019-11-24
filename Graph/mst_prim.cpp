#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;


#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
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

vector<pii>V[200];
int cost[200],takenby[200],vis[200];

struct Node
{
    int u,cost;
    Node() {}
    Node(int uu, int c)
    {
        u=uu;
        cost=c;
    }
};

bool operator<(Node A,Node B)
{
    if(A.cost>B.cost){
        return true;
    }
    else if (A.cost==B.cost){
        return A.u>B.u;
    }
    else return false;//printing the min vertex...while cost is equal
}

priority_queue<Node>pq;

void init(int n)
{
    for(int i=1; i<=n; i++)V[i].clear();

}

void prim(int n)
{
    for(int i=1; i<=n; i++)
    {
        cost[i]=inf;
        takenby[i]=-1;
        vis[i]=0;
        /*cout<<"i "<<i<<endl;
        for(auto xx : V[i])cout<<xx.fi<<" ";
        cout<<endl;*/
    }

    cost[1]=0;
    pq.push(Node(1,0));
    int ans=0;

    while(!pq.empty())
    {

        Node x = pq.top();
        pq.pop();

        if(vis[x.u])continue;
        vis[x.u]=1;
        //cout<<"xuxx "<<x.u<<endl;
        ans += x.cost;


        for(auto p: V[x.u])
        {

            if(vis[p.fi])continue;

            if(p.se < cost[p.fi])
            {
                pq.push(Node(p.fi,p.se));
                cost[p.fi]=p.se;
                takenby[p.fi]=x.u;
            }
            else if(takenby[p.fi]>x.u && p.se == cost[p.fi]) takenby[p.fi] = x.u;
        }

    }


    for(int i=1; i<=n; i++)
    {
        if(takenby[i]!=-1){
            cout<<takenby[i]<<" "<<i<<endl;
        }
    }

    cout<<ans<<"\nfinito\n\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    scn(t);

    while(t--)
    {
        int n,m;
        scn2(n,m);

        while(m--)
        {

            int u,v,c;
            scn2(u,v);
            scn(c);
            V[v].pb(mp(u,c));
            V[u].pb(mp(v,c));
        }
        prim(n);
        init(n);
    }
    return 0;
}
/*
6 9
2 4 4
1 3 1
1 4 3
2 3 4
3 4 2
3 6 4
4 6 6
5 6 2
1 2 4

3 3
1 3 2
1 2 1
2 3 1

6 6
1 2 2
2 3 2
3 6 2
5 6 2
4 5 2
1 4 2

*/

