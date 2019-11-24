#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

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
#define N 100005

int cnt[N], lps[N];

///https://codeforces.com/problemset/problem/432/D

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    int len = 0;
    string pat;
    cin>>pat;
    int M = pat.size();

    lps[0] = 0;

    int i = 1;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    for(int i=0; i<M; i++) cnt[lps[i]]++;
    for(int i=M-1; i>=0; i--){
        cnt[lps[i-1]] += cnt[i]; ///as many times lps of len i comes as many times lps of len j<i comes
    }

    vector<pii>ans;
   // for(int i=0; i<M; i++)cout<<lps[i]<<" ";
    while(M){
        ans.pb({M,cnt[M]});
        M = lps[M-1];
    }

    cout<<ans.size()<<endl;

    for(int i=ans.size()-1; i>=0 ; i--)cout<<ans[i].fi<<" "<<(ans[i].se+1)<<endl;


    return 0;
}
