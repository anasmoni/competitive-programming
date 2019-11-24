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
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define N ten(5)+7

int a[N];

///https://csacademy.com/contest/archive/task/min-races/statement/

/// exp a[] = {3,2,4,4,1}; ans is 3  --> {3,4} , {2,4}  , {1}
///idea..
/// Vec[] = {0,0,0,0,0};
/// i=1 , Vec[] = {0,0,0,0,3};
/// i=2 , Vec[] = {0,0,0,2,3};
/// i=3 , Vec[] = {0,0,0,2,4};
/// i=4 , Vec[] = {0,0,0,4,4};
/// i=5 , Vec[] = {0,0,1,4,4};

int main()
{
    ///freopen("debug.txt","w",stdout);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    int n,k;
    scn2(n,k);

    for(int x,y,i=1; i<=n; i++){
        scn2(x,y);
        a[y]=x;
    }

    vector<int>ans(n,0);
    int cnt=0;

    for(int i=1; i<=n; i++){

        auto x  = lower_bound(atoz(ans),a[i]);
        x--;
        *x = a[i]; /// look ....syntex (-__-)
    }


    for(auto x : ans)cnt += !x;


    cout<<(n-cnt);

    return 0;
}
