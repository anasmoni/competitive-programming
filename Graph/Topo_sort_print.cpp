#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GREY 2
#define BLACK 3
#define sz 1007

vector<int>V[sz];
int color[sz] , fin[sz] , beg[sz];

struct Node{

    int finish , val;

    Node(int f , int v){ finish = f , val = v ;}
};

bool operator<(Node A , Node B){return A.finish > B.finish;}

void DFS(int x , int &time){

    beg[x] = ++time;
    color[x] = GREY;

    for(int i : V[x]){

        if(color[i]==WHITE) DFS(i,time);
    }

    color[x] = BLACK; // no need here
    fin[x] = ++time;
}

void Topo_Sort(int n , int m){

    for(int i=1 ; i<=n; i++){

        color[i] = WHITE;
        fin[i] = beg[i] = 0;
    }

    for(int i=1 ; i<=m ; i++){

        int u,v;
        scanf("%d%d",&u,&v);

        V[u].push_back(v);
    }

    int time=0;

    for(int i=1 ; i<=n ; i++){

        if(color[i]==WHITE) DFS(i,time);
    }

    vector<Node>Topo;

    for(int i=1 ; i<=n ; i++) Topo.push_back(Node(fin[i],i));

    sort(Topo.begin() , Topo.end());

    for(Node x : Topo)cout<<x.val<<" ";
}


int main(){

    int n , m;
    scanf("%d%d",&n,&m);

    Topo_Sort(n,m);

    return 0;
}
