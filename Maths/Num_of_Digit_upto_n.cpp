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

int main()
{
    lli n;
    scnll(n);
    lli ans=0,cnt=0,nn=n,curr=1;

    lli i;
    for( i=1,cnt=1; ; i*=10LL,cnt++){
        if(i*10LL<=n){
            ans += cnt*i*9; /// 99-10 = 90 for two digits...thus
        }
        else break;
    }

    ans += cnt*(n-i+1);///say n=13, so (n-10+1)*2 = num of digits btwn 10 to 13

    cout<<ans;
    return 0;
}
