#include<bits/stdc++.h>
using namespace std;

/**http://codeforces.com/problemset/problem/429/A*/

int init[100007],gol[100007] , oka[100007];

vector<int>v[100007];
vector<int>node;

void dfs(int root , int e , int k){

    if(gol[root]!=init[root]^e){
        node.push_back(root);
        e^=1;
    }

    oka[root]=1;

    for(int i=0 ; i<v[root].size(); i++){
       if(oka[v[root][i]]==0)dfs(v[root][i],k,e);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1 ; i<n ; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
        v[x].push_back(y);

    }

    for(int i=1 ; i<=n ; scanf("%d",&init[i++]));

    for(int i=1 ; i<=n ; scanf("%d",&gol[i++]));

    dfs(1,0,0);

    printf("%d\n",node.size());

    for(int i=0 ; i<node.size() ; printf("%d\n",node[i++]));

    return 0;
}
