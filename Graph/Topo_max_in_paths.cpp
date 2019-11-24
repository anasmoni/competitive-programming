#include <bits/stdc++.h>
////#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ook order_of_key
#define fbk find_by_order
#define pb push_back
#define mp make_pair
#define intl long long
#define maxn 100005
#define ff first
#define ss second
#define bug printf ("bug\n")
#define sz(a) ((int)a.size())
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define si(a) scanf("%d" , &a)
#define sl(a) scanf("%lld" , &a)
#define sii(a,b) scanf("%d %d" , &a , &b)
#define sll(a,b) scanf("%lld %lld" , &a , &b)
#define FOR(i,a,b) for(intl i = (a) ; i <= (b) ; i++)
#define IN freopen("in.txt" , "r" , stdin)
#define OUT freopen("output2.txt" , "w" , stdout)
#define whats(x) printf ("x : %d\n" , x)


using namespace std ;
//using namespace __gnu_pbds;

typedef pair <int,int> pii ;
typedef pair <intl,intl> pll ;
//typedef tree < pii, null_type ,less<pii>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

/***************************************************************************************************/

///http://codeforces.com/problemset/problem/919/D
const int N = 3e5 + 5 , md = 1e9 + 7 ;
vector <int> g[N] ;
int n , m ;
char str[N] ;
int vis[N] ;
vector <int> sorted ;

void dfs (int u) {
    vis[u] = 1 ;
    for (auto v : g[u]) {
        if (vis[v] == 1) {
            cout << -1 ;
            exit(0) ;
        }
        if (vis[v] == 0) {
            dfs(v) ;
        }
    }
    vis[u] = 2 ;
    sorted.pb(u) ;
}

int dp[N][30] ;

int main () {

    cin >> n >> m ;
    scanf ("%s" , str+1) ;
    for (int i = 1 ; i <= m ;i++) {
        int u , v ;
        scanf ("%d %d" , &u , &v) ;
        if (u == v) {
            cout << -1 ;
            exit(0) ;
        }
        g[u].pb(v) ;
    }
    for (int i = 1; i <= n ; i++) {
        if (vis[i] == 0) {
            dfs(i) ;
        }
    }
    int ans = 0 ;
    for (auto u : sorted) {
        for (int i = 0 ; i < 26 ; i++) {
            for (auto v : g[u]) {
                dp[u][i] = max(dp[u][i],dp[v][i]) ;
            }
            if (str[u] - 'a' == i) {
                dp[u][i]++ ;
            }
            ans = max(ans , dp[u][i]) ;
        }
    }

    cout << ans << endl ;
}
