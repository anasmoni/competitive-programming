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
const int N = 1e6 + 5 ;

//http://codeforces.com/contest/862/problem/C

int main () {

    int n , x ;
    cin >> n >> x ;
    vector <int> ans ;

    if (x == 0) {
        if (n == 2) {
            printf ("NO") ; // cus, numbers should b distinct
            return 0 ;
        }
        else if (n == 1) {
            printf ("YES\n0") ;
            return 0 ;
        }

        int a = (1<<19) ;
        ans.pb(a) ;
        ans.pb(a+1) ;
        x = 1 ;
    }

    int bit = 0 ;

    while (((x>>bit)&1) == 0) bit++ ; // where the first one found

    int XOR = 0 ;

    for (int i = 1 ; i <= 1000000 ; i++) {
        if ((int)ans.size() == n-1) break ;
        if (((i>>bit)&1)==0) {
            ans.pb(i) ;
            XOR ^= i ;
        }
    }
    printf ("YES\n") ;
    sort (ans.begin(),ans.end()) ;

    for (int i = 0 ; i < ans.size() ; i++) {
        printf ("%d " , ans[i]) ;
    }
    printf ("%d" , XOR^x) ;
    return 0 ;
}
