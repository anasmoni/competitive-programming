#include<bits/stdc++.h>
using namespace std;

int a[25][25],n,m;

bool check()
{
    for(int i=0 ; i<n ; i++){int cnt=0 ; for(int j=0 ; j<m ; j++){if(a[i][j]==j+1)cnt++;}if(cnt<m-2){return false;}}
    return true;
}

int main()
{
    cin>>n>>m; for(int i=0 ; i<n ; i++)for(int j=0 ; j<m ; scanf("%d",&a[i][j++]));

    if(check()){cout<<"YES";return 0;}

    for(int i=0 ; i<m ; i++)
    {
        for(int j=i+1; j<m ; j++)
        {
            for(int k=0 ; k<n ; k++)swap(a[k][i],a[k][j]);
            if(check()){cout<<"YES";return 0;}
            for(int k=0 ; k<n ; k++)swap(a[k][i],a[k][j]);
        }
    }

    cout<<"NO";

    return 0;
}

