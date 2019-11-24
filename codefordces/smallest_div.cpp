#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}


///http://codeforces.com/problemset/problem/922/C

/// returns no if  for 1<=i<j<=k ; n%i == n%j

string fun(lli n, lli k){

    ///n%1==0 so we have to find smallest divisor d 1<d<=k
    n++;
    for(int i=2 ; i<=k ;i++){
        if(n%i)return "No";
    }


    return "Yes";
}

int main()
{
    ///freopen("debug.txt","w",stdout);
    lli n,k;
    cin>>n>>k;
    cout<<fun(n,k);


    return 0;
}
