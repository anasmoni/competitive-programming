#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define atoz(v) v.begin(),v.end()
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

void vector_array(vector<int>*v, int n){

    for(int i=0 ; i<n; i++){
        for(int j=0; j<v[i].size(); j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }

    cout<<"array of vector.......\n";
}

void fun(vector<vector<int> >&vv){

    for(auto v: vv)
    {
        for(auto x : v)cout<<x<<" ";
        cout<<endl;
    }
}

int main(){

    vector<int>v[2323];

     for(int i=0 ; i<10; i++){
        for(int j=0; j<=12; j++)v[i].pb(j);
    }

    vector_array(v,10);

    vector< vector<int> >vv;

    for(int i=0 ; i<10; i++){
            vector<int>temp;
        for(int j=0; j<=12; j++)temp.pb(j);
        vv.pb(temp);
    }

    fun(vv);


    return 0;
}

