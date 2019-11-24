#include<bits/stdc++.h>
using namespace std;

#define sz 500005

/**
given array a and sum (u,v)

if x,c,v,f,g,h,j are connected then we can replace any of them by others of them in array a

we have to replace such a way ..so that at last we get the longest palindromic subsequenc

print the lps

**/

int parent[sz];

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

int main()
{
    int n,m,k,u,v;
    scanf("%d%d%d",&n,&k,&m);

    for(int i=1 ; i<=n ; i++)parent[i]=i;

    while(k--)
    {

        scanf("%d%d",&u,&v);

        if(Find(u)!=Find(v)) parent[ parent[u] ] = parent[v];
    }

    int a[m+1];

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d",&a[i]);
        a[i] = Find(a[i]);
    }

    /*for(int i=0; i<m ; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;*/



    int i, j, cl;
    int L[m][m];

    for (i = 0; i < m; i++) L[i][i] = 1;


    for (cl=2; cl<=m; cl++)
    {
        for (i=0; i<m-cl+1; i++)
        {
            j = i+cl-1;
            if (a[i] == a[j] && cl == 2)L[i][j] = 2;

            else if (a[i] == a[j]) L[i][j] = L[i+1][j-1] + 2;

            else L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    printf("%d",L[0][m-1]);


    return 0;
}
