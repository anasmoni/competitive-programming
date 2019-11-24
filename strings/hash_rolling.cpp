#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
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
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

///priority_queue< int, vector< int >, greater< int > > minHeap;

#define N 1000003
///https://codeforces.com/contest/1056/problem/E
lli p_pow[N] , freq[2] , H[N] , MOD = 1e9 + 7 , p = 31;
char s[N] , t[N];

lli Hash(int lo,  int hi , int n){

    lli ret = (H[hi]-H[lo-1]+MOD) % mod;
    ret = (ret * p_pow[n-lo])%MOD;

    return ret;
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    scanf("%s%s",s+1,t+1);

    int len_s = strlen(s+1) , len_t = strlen(t+1) , ans = 0;

    p_pow[0] = 1;

    for(int i=1; i<N; i++) p_pow[i] = (p_pow[i-1] * p) % MOD;

    for(int i=1; i<=len_s ; i++) freq[s[i]-'0']++;

    for(int i=1; i<=len_t ; i++) H[i] = (H[i-1] + p_pow[i]*(t[i]-'0'+1)) % MOD;

    int max_freq = 0 , min_freq = 1;

   // if(freq[0]<freq[1]) swap(max_freq , min_freq);



    for(int lenA = 1; lenA<=len_t ; lenA++){

        if( (lenA*freq[max_freq]) > len_t ||  (len_t - lenA*freq[max_freq])<freq[min_freq]){
            break;
        }

        if( (len_t - lenA*freq[max_freq])%freq[min_freq]) continue;

        int lenB = (len_t - lenA*freq[max_freq])/freq[min_freq];

        int pos = 1;
        lli HashA , HashB;
        HashA = HashB = -1;

        bool ok = true;

        for(int j=1; j<=len_s; j++){

            if(s[j]-'0' == max_freq){
                if(HashA == -1) HashA = Hash(pos,pos+lenA-1 , len_t);
                else if(HashA != Hash(pos,pos+lenA-1, len_t)){
                    ok = false;
                    break;
                }
                pos += lenA;
            }
            else{
                if(HashB == -1) HashB = Hash(pos,pos+lenB-1, len_t);
                else if(HashB != Hash(pos,pos+lenB-1, len_t)){
                    ok = false;
                    break;
                }
                pos += lenB;
            }
        }
        ans += (ok && HashA != HashB);

    }


    cout<<ans;

    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)

