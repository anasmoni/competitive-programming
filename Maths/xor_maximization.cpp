#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
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

///http://www.spoj.com/problems/XMAX/

/** given an array 1<=ai<=1e18
    Find a subset such that xor of all elements of this subset becomes maximum
*/

///https://www.hackerearth.com/practice/notes/gaussian-elimination/

///http://math.stackexchange.com/questions/48682/maximization-with-xor-operator

int bit_len(lli n){
    int cnt=0;

    while(n){
        n >>= 1LL;
        cnt++;
    }

    return cnt;
}

int main()
{
    ///freopen("debug.txt","w",stdout);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    int n;
    scn(n);

    lli a[n];
    vector<lli>V[65];

    for(int i=0; i<n; i++){
        cin>>a[i];
        V[bit_len(a[i])].pb(a[i]);
    }

    lli Forward_Eleminated[70];
    int len=0;

    for(int i=64; i ; i--){

        if(V[i].size() == 0)continue;

        Forward_Eleminated[len++] = V[i][0];

        for(int j=1; j<V[i].size(); j++){

            lli temp = V[i][0]^V[i][j];

            V[bit_len(temp)].pb(temp);
        }
    }
    lli ans = 0;

    for(int i=0; i<len; i++) ans = max(ans , ans^Forward_Eleminated[i]);

    cout<<ans;


    return 0;
}
