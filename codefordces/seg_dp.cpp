#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int n,k,q,a,b,x[N],y[N],i;

/**http://codeforces.com/problemset/problem/816/B**/

int main()
{

    cin>>n>>k>>q;

    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        x[a]++;
        x[b+1]--;
    }

    for(i=1; i<N; i++)
    {
        x[i]+=x[i-1];
        y[i]+=y[i-1]+(x[i]>=k);
    }

    for(i=0; i<q; i++)
    {
        cin>>a>>b;
        cout<<y[b]-y[a-1]<<'\n';
    }

}
