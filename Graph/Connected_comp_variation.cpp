#include<bits/stdc++.h>
#define N 10005
/**https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2870**/
using namespace std;

vector <int> Edges [N];
vector <int> rEdges [N];
bool vis [N];
stack<int>stk;
int comp[N] , in[N];

void reset (int n)
{
    for ( int i = 1; i <= n; i++ ) {

        Edges [i].clear ();
        rEdges [i].clear ();
        vis[i]=false;
        in[i]=0;
        if(!stk.empty())stk.pop();
    }
}

void dfs1 (int x)
{
    vis [x] = true;

    for ( auto i : Edges[x])

        if ( !vis[i] ) dfs1(i);

    stk.push(x);
}

void dfs2 (int x, int c)
{
    vis [x] = false;
    comp [x] = c;

    for ( auto i : rEdges[x])

        if ( vis[i] ) dfs2(i,c);
}

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    int cases = 0;

    while ( testCase-- ) {

        int n, m,a,b;
        scanf ("%d %d", &n, &m);
        reset(n);

        while(m--) {

            scanf ("%d %d", &a, &b);
            Edges [a].push_back (b);
            rEdges [b].push_back (a);
        }

        for ( int i = 1; i <= n; i++ )

            if ( !vis [i] ) dfs1 (i);

        int c = 0;

        while(!stk.empty()){

            int i = stk.top();
         //   cout<<i<<" ";
            if ( vis[i]) dfs2(i, ++c);
            stk.pop();
        }
        //cout<<c<<endl;
        for ( int i = 1; i <= n; i++ ) {
            //cout<<comp[i]<<" ";
            for (auto j : Edges[i])

                if ( comp [i] != comp[j])  in[comp[j]]++;
        }

        int cnt = 0;

        for ( int i = 1; i <= c; i++ )cnt+=(!in[i]);//cout<<in[i]<<" ";}

        printf ("Case %d: %d\n", ++cases, cnt);
    }

    return 0;
}

/*
7 8
1 2
3 1
2 3
4 2
2 5
6 5
6 7
4 7
*/
