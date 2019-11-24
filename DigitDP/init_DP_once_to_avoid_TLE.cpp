#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

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
#define mod 1000000007

/// given A,B, (1<=A<=B<=1e50) how many number has count(3)==count(6)==count(9) in betwn [A,B]

const int NX = 52 , CX = 17;

lli dp[2][CX][CX][CX][NX];

int max_freq = 16;
string s;

lli DP( int pos , int three , int six , int nine, int isSmall)
{
    if(pos == s.size()){
        if(six == nine && six == three && six>0) return 1;
        return 0;
    }

    if(six>max_freq || nine>max_freq || three>max_freq) return 0;

    lli &ret = dp[isSmall][three][six][nine][pos];

    if(isSmall && ret != -1 ) return ret;
    /// isSmall checking is due to appending 0's and not taking isStart state

    int ses = isSmall ? 9 : s[pos]-'0';
    int i ;
    ret = 0 ;


        for ( i = 0 ; i <= ses ; i++ )
        {

    ret += DP( pos+1,three+(i==3),six+(i==6), nine+(i==9),isSmall | i < (s[pos]-'0') );
            ret %= mod;
        }

    return ret ;
}

void proc(string A){ /// if all string has same length then doing Fill(dp,-1) once will be OK
    s = A;
    while(s.size()<50) s = "0" + s;
}

int main()
{
    int cs, t ;
    scanf("%d",&t);

    memset(dp,-1,sizeof dp);

    for ( cs = 1 ; cs <= t ; cs++ )
    {

        string A,B;
        cin>>A>>B;

        proc(B);
        lli ans = DP(0,0,0,0,0);

        int three=0 , six=0 , nine=0;

        for(int i=0; i<A.size(); i++){
            if(A[i] == '3') three++;
            if(A[i] == '6') six++;
            if(A[i] == '9') nine++;
        }

        if(six == nine && nine == three && six>0) ans++;

        proc(A);
        ans = (ans - DP(0,0,0,0,0) + mod) % mod;

        printf("%lld\n",ans);
    }
    return 0;
}
