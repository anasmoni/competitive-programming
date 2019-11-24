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
#define ratoz(v) v.rbegin(),v.rend()
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

lli dp[1<<18][20];
int C[400][400];
///https://codeforces.com/contest/580/problem/D
int bit(int n){
    int cnt=0;

    while(n){
        if(n%2)cnt++;
        n /= 2;
    }
    return cnt;
}

int main()
{
    ///freopen("debug.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */

    int n,m,k;
    scn3(n,m,k);

    int a[n];

    for(int i=0; i<n; i++) scn(a[i]);

    for(int i=1; i<=k; i++){

        int x,y,c;
        scn3(x,y,c);
        x--;y--;
        C[x][y] = c;
    }

    lli ans=0;

    for(int mask=0; mask<(1<<n); mask++){

        for(int i=0; i<n; i++){

            if(check(mask,i))continue;
            int curr = (mask|(1<<i));
            if(mask){
                for(int j=0; j<n; j++){

                    if(j == i || check(mask,j) == false)continue;

                    dp[curr][i] = max(dp[curr][i], dp[mask][j] + C[j][i] + a[i]);
                }
            }
            else dp[curr][i] = a[i];
            //cout<<curr<<"  ------ "<<bit(curr)<<" dp  "<<dp[curr][i]<<endl;
            if(m >= bit(curr)){
                //if(dp[curr][i]>ans)cout<<curr<<" ---- "<<dp[curr][i]<<endl;
                ans = max(dp[curr][i],ans);
            }
        }
    }

    cout<<ans;


    return 0;
}
