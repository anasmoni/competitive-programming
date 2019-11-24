#include<bits/stdc++.h>
using namespace std;

/** for baisc code see page 152 shanto vi cz it's a implementation ...
..problem lightOj 1041 - Road Construction*/


struct Edge{
    string u,v;
    int w;
    Edge(string uu,string vv, int ww){
        u=uu;
        v=vv;
        w=ww;
    }
};

bool operator<(Edge A , Edge B) {return A.w<B.w;}

map<string,string>parent;

string Find(string x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

int kruskal(int m){

    vector<Edge>E;
    set<string>stin;

    while(m--){
        string u,v;
        int w;
        cin>>u>>v>>w;
        parent[u]=u;
        parent[v]=v;
        E.push_back(Edge(u,v,w));
        stin.insert(u);
        stin.insert(v);
    }

    sort(E.begin(),E.end());
    int sz = E.size();
    int ans=0;


    for(int i=0 ; i<sz ; i++){
        if(Find(E[i].u) != Find(E[i].v)){
            parent[ parent[E[i].u] ] = parent[ E[i].v ];
            ans += E[i].w;
        }
    }

    set<string>::iterator it = stin.begin();

    /*for( ; it!=stin.end(); it++){//check if all vertexes are in the same union set
        set<string>::iterator t = it;
        t++;
        for( ; t!=stin.end();t++){
            if(Find(*it)!=Find(*t))return -1; // it get AC too.....
        }
    }*/

    set<string>sets; /** how many connected comp sets.....here should be 1... */

    for(; it!=stin.end(); it++){
        sets.insert(Find(*it));
    }
    if(sets.size()>1)return -1;

    return ans;

}

int main(){

    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++){
        int n;
        scanf("%d",&n);
        n = kruskal(n);
        if(n>=0)printf("Case %d: %d\n",tc,n);
        else cout<<"Case "<<tc<<": Impossible\n";
    }

}
