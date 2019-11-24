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

///https://codeforces.com/problemset/problem/401/D

///given n [1,1e18] and mod [1,100]
/// find how many permutation of n(without leading zero) is divisible by m
/// exp : 104 2 ; so , ans is 3 cause, 140,410,104

lli dp[1<<18][101] , fact[20];
int freq[11];

int main()
{
    ///freopen("debug.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    string s;
    int mod,n;

    cin>>s>>mod;
    n = s.size();

    for(int i=0; i<n; i++) freq[s[i]-'0']++ ;
    fact[0]=1;
    for(int i=1; i<=19; i++) fact[i] = fact[i-1]*i;

    int mx = (1<<n)-1;

    dp[0][0]=1; ///base case

    for(int mask=0; mask<=mx; mask++){

        for(int i=0; i<n; i++){

            if(check(mask,i))continue;

            for(int m=0; m<mod; m++){

                if(!mask && s[i]=='0')continue;

                dp[mask|(1<<i)][(m*10+s[i]-'0')%mod] += dp[mask][m];

                /**
                suppose , num = number that came from old_mask (if n = 1234 , old_mask=101 then num = 13)

                dp[new_mask][(num*10 + s_i)%mod] += dp[old_mask][num%mod];



                **/
            }
        }
    }

    lli denom = 1;

    for(int i=0; i<10; i++) denom *= fact[freq[i]];

    cout<<dp[mx][0]/denom;

    return 0;
}
