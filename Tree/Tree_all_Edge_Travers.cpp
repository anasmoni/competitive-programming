#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define sz 100007
int a=-1,b=-1;
vector<int>V[sz] ;
vector<pii>VXD[sz];
vector<int>ans;
int visited[sz],da[sz],db[sz] ;
int done[sz];

void bfs(int x)
{

    queue<int>q;
    q.push(x);
    memset(visited,0,sizeof(visited));
    visited[x]=1;

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(int i=0 ; i<V[x].size(); i++)
        {
            int h = V[x][i];
            if(visited[h]==0)
            {
                visited[h]=1;
                q.push(h);
                if(b<0)da[h] = da[x] +1;
                else db[h] = db[x] + 1;

            }
        }
    }
}

void dfs(int x, int p , bool ne=false)
{

    ans.push_back(x);
    visited[x] = 1;
    int sxv = VXD[x].size();

    for(int i=0 ; i<sxv; i++)
    {
        int v = VXD[x][i].second;

        if(visited[v]==0){
            dfs(v,x,ne||(i<sxv-1));
        }
    }

    if(ne)ans.push_back(p);
}

void solve(int n)
{

    for(int i=1 ; i<n ; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
    }


    bfs(1);
    int mx=-1;

    for(int i=1 ; i<=n ; i++)
    {
        if(mx<da[i])
        {
            mx=da[i];
            a=i;
        }
    }

    memset(da,0,sizeof(da));
    bfs(a);

    mx=-1;
    for(int i=1 ; i<=n ; i++)
    {
        if(mx<da[i])
        {
            mx=da[i];
            b=i;
        }
    }

    for(int i=1; i<=n; i++){
        for(auto x : V[i]){
            VXD[i].push_back(pii(da[x],x));
        }
        sort(VXD[i].rbegin(),VXD[i].rend());
    }

    memset(visited,0,sizeof(visited));
    dfs(b,-1);
    printf("%d\n",ans.size()-1);

    for(int i=0 ; i<ans.size(); i++)
    {
        printf("%d",ans[i]);
        if(i<ans.size()-1)printf(" ");
    }

}

int main()
{

    int n;
    scanf("%d",&n);
    solve(n);



    return 0;
}
/**Algorithm:

1. Run a BFS from any node and determine the farthest node from it and Name this node as b.
2. Run another BFS from b and save all node’s distance from b (dis array). and determine the farthest node from b and name this node as a;
3. Run another BFS from a and save all nodes distance from a (dis1 array).
4. Now print for all node max(dis[node], dis1[node]).


9
1 2
1 5
2 4
2 3
5 6
5 7
6 8
6 9

**/
