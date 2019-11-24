#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
/**http://www.lightoj.com/volume_showproblem.php?problem=125**/

int a=-1,b=-1,temp=0,ans=-1;
map<pii,int>cost;
vector<int>V[30007];
int visited[30007],da[30007] ,db[30007] ;

void bfs(int x){

    queue<int>q;
    q.push(x);
    memset(visited,0,sizeof(visited));
    visited[x]=1;

    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=0 ; i<V[x].size(); i++){
            int h = V[x][i];
            if(visited[h]==0){
                visited[h]=1;
                q.push(h);
                if(b<0)da[h] = da[x] + cost[pii(h,x)];
                else db[h] = db[x] + cost[pii(h,x)];

            }
        }
    }
}



void init(int n){

    for(int i=0 ; i<n; i++){
        da[i]=0;
        db[i]=0;
        V[i].clear();
    }
    a=-1;
    b=-1;
    cost.clear();
}

void solve(int n,int tc){

    init(n);

    for(int i=0 ; i<n-1 ; i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        cost[pii(u,v)]=c;
        cost[pii(v,u)]=c;
        V[u].push_back(v);
        V[v].push_back(u);
    }


    bfs(0);
    int mx=-1;

    for(int i=0 ; i<n ; i++){
        if(mx<da[i]){mx=da[i];a=i;}
    }

    memset(da,0,sizeof(da));
    bfs(a);

    mx=-1;
    for(int i=0 ; i<n ; i++){
        if(mx<da[i]){mx=da[i];b=i;}
    }

    bfs(b);

    printf("Case %d:\n",tc);

    for(int i=0 ; i<n ; i++){
        printf("%d\n",max(da[i],db[i]));
    }

}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1 ; tc<=t; tc++){
        int n;
        scanf("%d",&n);
        solve(n,tc);

    }

    return 0;
}
/**Algorithm:

1. Run a BFS from any node and determine the farthest node from it and Name this node as b.
2. Run another BFS from b and save all node’s distance from b (dis array). and determine the farthest node from b and name this node as a;
3. Run another BFS from a and save all nodes distance from a (dis1 array).
4. Now print for all node max(dis[node], dis1[node]).

**/
