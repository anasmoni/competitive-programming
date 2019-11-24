#include<bits/stdc++.h>
using namespace std;

vector<int>V[10007];
int n,m , vis[10007];

bool dfs(int x , int parent){
    vis[x]=1;

    for(int i : V[x]){
        if(!vis[i]){if(dfs(i,x))return true;}
        else if(i!=parent)return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    if(m!= n-1 || n==1){cout<<"NO";return 0;}

    while(m--){

        int u,v;
        scanf("%d%d",&u,&v);
        V[v].push_back(u);
        V[u].push_back(v);
    }

    for(int i=1 ; i<=n ; ++i){
        if(vis[i])continue;
        if(dfs(i,-1)){cout<<"NO";return 0;}
    }
    cout<<"YES";

    return 0;
}
