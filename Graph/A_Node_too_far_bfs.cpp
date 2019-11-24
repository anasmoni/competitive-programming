#include<bits/stdc++.h>
using namespace std;
#define inf 1000000009
map<int,int>vis;
int n;

/**https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=272**/

int bfs(int x ,int ttl , map<int , vector<int> > V){

    vis[x]=0;
    queue<int>Q;
    Q.push(x);

    while(!Q.empty()){

        x = Q.front();
        Q.pop();

        for(int i : V[x]){

            if(!vis.count(i)){
                vis[i] = vis[x] + 1;
                Q.push(i);
            }
        }
    }
    int cnt=0;

    for(auto i : vis){
        if(i.second>ttl)cnt++;
    }

    cnt += V.size()-vis.size();
    return cnt;
}


int main()
{
    for(int t=1 ;  ; ){

        scanf("%d",&n);
        if(!n)break;
        map<int , vector<int> >V;


        while(n--){

            int u,v;
            scanf("%d%d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }

        while(true){

            int source , ttl , cant;
            scanf("%d%d",&source,&ttl);
            if(!source && !ttl)break;
            vis.clear();

            cant = bfs(source , ttl , V);

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t++,cant,source,ttl);
        }



    }
    return 0;
}
