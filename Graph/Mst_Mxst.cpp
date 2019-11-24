#include<bits/stdc++.h>
using namespace std;

/** http://www.lightoj.com/volume_showproblem.php?problem=1029 civil the evil.....*/

struct Edge{
    int u,v;
    int w;
    Edge(int uu,int vv, int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};

bool operator<(Edge A , Edge B) {return A.w<B.w;}

int parent[111];

int Find(int x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

vector<Edge>E;

int kruskal(int m){


    for(int i=0 ; i<=m; i++)parent[i]=i;

    while(1){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(!u && !v && !w)break;

        E.push_back(Edge(u,v,w));
    }

    sort(E.begin(),E.end());
    int sz = E.size();
    int ans=0;
    int mn=1000000;

    for(int i=0 ; i<sz ; i++){
        if(Find(E[i].u) != Find(E[i].v)){
            parent[ parent[E[i].u] ] = parent[ E[i].v ];
            ans += E[i].w;
        }
        else if(E[i].w<mn)mn=E[i].w;
    }

    return ans;
}

int maxim(int m){

    for(int i=0 ; i<=m; i++)parent[i]=i;

    sort(E.rbegin(),E.rend());

    int sz = E.size();
    int ans=0;
    int mn=-1;

    for(int i=0 ; i<sz ; i++){
        if(Find(E[i].u) != Find(E[i].v)){
            parent[ parent[E[i].u] ] = parent[ E[i].v ];
            ans += E[i].w;
        }
        else if(E[i].w>mn)mn=E[i].w;
    }
    E.clear();
    return ans;
}

int main(){

    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++){
        int n;
        scanf("%d",&n);
        int k = kruskal(n) + maxim(n);
        if(k%2==0)printf("Case %d: %d\n",tc,k/2);
        else printf("Case %d: %d/2\n",tc,k);
    }

}
