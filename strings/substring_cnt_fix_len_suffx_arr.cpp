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

/// given string s, how many unique substr here of length in betwn [lo,hi]

#define MAXN 65536
#define MAXLGN 17

struct Entry{
    int pos;
    pii prio;

}L[MAXN];

int S[MAXLGN][MAXN]; ///suffix array , Last row of S is suffix array of string s

int cmp(struct Entry a ,struct Entry b){

    return (a.prio<b.prio);
}

int LCP(int n , int stp, int lo, int hi){ /// for understanding , see standford's pdf

    if(lo == hi) return n-lo;

    int ret = 0;

    for(int k=stp-1; k>=0 && lo<n && hi<n ; k--){

        if(S[k][lo] == S[k][hi]){
            int temp = (1<<k);
            ret += temp;  /// tight time limit?? handle this
            lo += temp;
            hi += temp;
        }
    }
    return ret;
}

bool IN(int x , int lo,int hi){
    return (lo<=x && x<=hi);
}

int fun(string s , int lo, int hi){ /// for understanding , see standford's pdf

    int n = s.size();

    for(int i=0; i<n; i++){

        S[0][i] = s[i]-'a';
    }
    int stp=1;
    for(int cnt = 1; (cnt>>1) < n ; stp++ , cnt <<= 1){

        for(int i=0; i<n; i++){

            L[i].prio.fi = S[stp-1][i];
            L[i].prio.se = (i+cnt < n) ? S[stp-1][i+cnt] : -1;
            L[i].pos = i;
        }
        sort(L,L+n,cmp);

        for(int i=0; i<n; i++){

            S[stp][L[i].pos] = (i>0 && L[i-1].prio == L[i].prio) ? S[stp][L[i-1].pos] : i;
        }
    }

    vector<pii>v;

    for(int i=0; i<n; i++){
        v.pb({S[stp-1][i],i});
    }

    sort(atoz(v));

    int temp = n-v[0].se;
    int ret = temp;
    ret -= min(temp , lo-1);
    ret -= max(temp-hi,0);

    for(int i=1; i<v.size(); i++){

        int a = v[i].se;
        int b = v[i-1].se;

        int l = LCP(n,stp,a,b) , len = n-v[i].se;

        ret += len-l;

        ret -= max(0, min(len-l , lo-l-1));
        ret -= max(0 , min(len-l,len-l-(hi-l)));
    }

    return ret;
}

int main()
{
  ///  freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    int t;
    scn(t);

    for(int cs=1; cs<=t; cs++){

        string s;
        cin>>s;
        int a,b;
        scn2(a,b);

        printf("Case %d: %d\n",cs,fun(s,a,b));
    }
    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
