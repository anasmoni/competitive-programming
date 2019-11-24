#include<bits/stdc++.h>
using namespace std;

#define sz 500005

/** https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734 **/

int parent[sz];
int n,t,u,v;
char c;

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

int main()
{
    scanf("%d",&t);

    string line;

    while(t--)
    {
        int yup, nope;
        yup=nope = 0;
        scanf("\n%d\n",&n);

        for(int i=1 ; i<=n ; i++)parent[i]=i;

        while(true)
        {
            if(!getline(cin,line) || line.empty()) break;
            sscanf(line.c_str(),"%c %d %d",&c,&u,&v);

            if(c == 'c'){
                if(Find(u)!=Find(v))
                    parent[ parent[u] ] = parent[v];
            }

            else   Find(u)==Find(v) ? yup++ : nope++;

        }

        printf("%d,%d\n",yup,nope);
        if(t) printf("\n");
    }

    return 0;
}
