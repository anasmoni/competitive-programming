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

void mor(){cout<<"NO"; exit(0);}

/// https://codeforces.com/contest/1163/problem/D

/** given S (contains 'a'-'z' or '*'  , '*' can be replaced by any char 'a'-'z')
given A,B , maximize (Occurrence of A in S - Occurrence of B in S)
 */

/**

Problem D : (Just Discussing a solution)

1. Given strings S and A , both contain lowercase English char only , we have to count how many occurrences
 of A in S. ...what we will do?..KMP right? so , we have LPS[] for string A.

( LPS[i] = length of " longest prefix which is also suffix " of sub-string A[0...i]) .
Let's make an recursive implementation of KMP.

2. Now assume S can have some '*' which can be replaced by any char in between 'a'-'z' .
How many occurrences now ?....KMP again..but we need LPS[i][c] now.

Where LPS[i][c] = length of " longest prefix which is also suffix " of string( A[0...i] + (char)(c+'a') );
 what change will come in our above recursive solution?...

3. Now come to our actual problem D. We need two different lps arrays LPS_A[][] and LPS_B[][] .
 how the func will change now?


4. we're actually done!..just need to pre-calculate two LPS arrays using brute force and
 trivial dp memoization

**/

string s,a,b;

int dp[1005][53][53];
int lpsA[55][30] , lpsB[55][30];

void Init(){

    cin>>s>>a>>b;

    for(int i=0; i<1005; i++){
        for(int j=0; j<53; j++){
            for(int k=0; k<53; k++) dp[i][j][k] = -inf;
        }
    }
}

void preCalc_LPS(char who){
    string s;

    if(who == 'a') s = a;
    else s = b;

    int n = s.size();

    for(int prfx=0; prfx<=n; prfx++){

        string prefix = s.substr(0,prfx);

        for(int c=0 ; c<26; c++){

            prefix += (char)(c+'a');

            for(int lps = min(prfx+1,n) ; lps ; lps--){

                string p = s.substr(0,lps);
                string suffix = prefix.substr(sz(prefix)-lps);

                if(p == suffix){
                    if(who == 'a') lpsA[prfx][c] = lps;
                    else lpsB[prfx][c] = lps;
                    break;
                }
            }
            prefix.pop_back();
        }
    }
}

int fun(int pos , int la , int lb){

    if(pos == s.size()) return 0;

    int &ret = dp[pos][la][lb];

    if(ret != -inf) return ret;

    int lo = 0 , hi = 25;

    if(s[pos] != '*') lo = hi = s[pos]-'a';

    for( ; lo<=hi ; lo++){

        int matchA = lpsA[la][lo];
        int matchB = lpsB[lb][lo];

        int now = (matchA == sz(a)) - (matchB == sz(b)) + fun(pos+1,matchA , matchB);
        ret = max(now,ret);
    }
    return ret;
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    Init();
    preCalc_LPS('a');
    preCalc_LPS('b');

    cout<<fun(0,0,0);

    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
