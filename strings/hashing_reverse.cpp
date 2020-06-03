#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define fast_io ios_base::sync_with_stdio(0); //cin.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define loop(i,n) for(i=1;i<=n;i++)
#define loon(i,n) for(i=n;i>0;i--)
#define pii pair< int,int > 
#define pll pair< ll,ll > 
#define vii vector< int > 
#define vll vector< ll > 
#define vss vector< string > 
#define vdd vector< double > 
#define vpi vector< pii > 
#define vpl vector< pll > 
#define vvi vector< vii > 
#define vvl vector< vll > 
#define PQ priority_queue
#define MX 5000001
#define mod 1000000007
#define INF 10000000000000
#define EPS 1e-12

/* Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
pii(ll,ll),					// type long long
null_type,
less<pii(ll,ll)>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct compare{
    bool operator() (ll a, ll b)
    {
        return a>b;
    }
};

const ll mod1=1000000007;
const ll mod2=1000000207;
const ll p1=131,p2=163;

string str;

///https://codeforces.com/contest/7/submission/50162954
int main()
{

    fast_io;
    ll n,m,t,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);

    cin>> str;
    pll pw=pll(1,1);

    ll res[str.size()+1],sum=0;
    res[0]=0;
    pll pp=pll(0,0);
    pll qq=pll(0,0);
    for(i=1;i<=str.size();i++){
        pp.first=(pp.first+(str[i-1]*pw.first)%mod1)%mod1;
        pp.second=(pp.second+(str[i-1]*pw.second)%mod2)%mod2;
        qq.first=((qq.first*p1)%mod1+str[i-1])%mod1;
        qq.second=((qq.second*p2)%mod2+str[i-1])%mod2;
        pw.first*=p1;pw.first%=mod1;
        pw.second*=p2;pw.second%=mod2;
        //cout<< p.first << ' ' << p.second << endl;
        //cout<< q.first << ' ' << q.second << endl;
        if(pp==qq)
            res[i]=res[i/2]+1;
        else
            res[i]=0;
        sum+=res[i];
    }

    cout<< sum << endl;

    return 0;
}
