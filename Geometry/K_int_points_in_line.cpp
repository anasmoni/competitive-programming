
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

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

///https://csacademy.com/contest/archive/task/integer-coords/statement/

    ///The number of lattice (integer) points on the line determined by
    /// the points (a, b) and (c, d) is gcd(|a - c|, |d - b|) + 1

int main()
{
    ///freopen("debug.txt","w",stdout);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    int n,m,k ,ans=0;
    scn3(n,m,k);

    k--;

    for(int x1=0; x1<=n; x1++){
        for(int y1=0; y1<=m; y1++){
            for(int x2=0; x2<=n; x2++){
                for(int y2=0; y2<=m; y2++){

                    if(x1==x2 && y1==y2)continue;

                    int x = abs(x1-x2);
                    int y = abs(y1-y2);

                    if(__gcd(x,y)==k)ans++;
                }
            }
        }
    }



    printf("%d",ans/2);



    return 0;
}
