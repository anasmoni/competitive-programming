#include <bits/stdc++.h>
#define N 100007
using namespace std;

/**http://codeforces.com/problemset/problem/580/C**/

vector<int> v[N];
int D[N],n,m,ans=0;

void DFS(int x,int y, int cnt)
{
    if(D[y])cnt++;
    else cnt=0;
    if(cnt>m)return ;
    if(v[y].size()==1 && y!=1)ans++;
    for(int j=0; j<v[y].size(); j++)
        if(v[y][j]!=x)DFS(y,v[y][j],cnt);
}

int main()
{
    cin>>n>>m;

    for(int i=1; i<=n; cin>>D[i++]);

    for(--n; n; n--)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS(-1,1,0);

    cout<<ans;
}
