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

///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2629

/// given a,b,n find fib(a^b) mod n               (0 <= a) , (b < 2^64) , (1 <= n <= 1000)

/// a,b is ~= 10^19 use unsigned long long

template <typename T>
T mod(T a, T b, T c)
{
    if(b==0) return 1;

    if(b%2==0)
    {
        T x=mod(a,b/2,c);
        return (x%c*x%c)%c; /// to avoid overflow as may x >= 10^10
    }
    else return (a%c * mod(a,b-1,c))%c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /// idea n<=1000 , so [0,n-1] numbers  so we will find cycle in after generating at most n^2 len sequence

    vector<int>Cycle[1003];

    for(int i=2; i<=1000; i++){

        Cycle[i].pb(0);
        Cycle[i].pb(1);
        Cycle[i].pb(1);
        int curr = 2;

        while(1){

            int x = Cycle[i][curr] + Cycle[i][curr-1];
            /// look we need not to comput actual fib...as fib[i] % n = ( fib[i-1] + fib[i-2] ) % n
            x %= i;
            Cycle[i].pb(x);

            if(x==1 && Cycle[i][curr]==0)break; /// ... 0 , 1,,,repeatation found so done

            curr++;

        }
    }

    int t;
    cin>>t;

    while(t--){

        unsigned long long  a,b,n , len;
        cin>>a>>b>>n;

        if(n==1 || !a){
            cout<<0<<endl;
            continue;
        }

        len = Cycle[n].size() - 2LL; /// Cycle length
        //cout<<len<<endl;

        cout<< Cycle[n][ mod(a,b,len) ] <<endl;
    }

}
