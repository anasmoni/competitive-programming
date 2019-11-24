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

///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1160 ----uva - 10219 Find the ways

/// no of digits in nCr

/// look-------------- no  of digit in a number n = floor( log10(n) ) + 1

double log10(double n){
    return log(n)/log(10);
}

int main()
{
    ///freopen("debug.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout<<M_PI;
    lli n,k;
    while(scn2ll(n,k)==2){

        double ans=0;

        for(int i=0; i<k; i++) ans += log10(n-i) - log10(i+1);

        int dig = floor(ans)+1;

        cout<<dig<<endl;
    }

    return 0;
}

/**
         No  of digits in factorial for O(n)

-----------------------------------IDEA------------------------------------------------------

    we know,
    log(a*b) = log(a) + log(b)

    Therefore
    log( n! ) = log(1*2*3....... * n)
              = log(1) + log(2) + ........ +log(n)

    Now, observe that the floor value of log base
    10 increased by 1, of any number, gives the
    number of digits present in that number.

    Hence, output would be : floor(log(n!)) + 1.



    int findDigits(int n)
    {
        // factorial exists only for n>=0
        if (n < 0)
            return 0;

        // base case
        if (n <= 1)
            return 1;

        // else iterate through n and calculate the
        // value
        double digits = 0;
        for (int i=2; i<=n; i++)
            digits += log10(i);

        return floor(digits) + 1;
    }
*/
/**

------------no of digits in factorial when n is large-------------O(1)

approximate formulla for large n

long long findDigits(int n)
{
    // factorial of -ve number doesn't exists
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // Use Kamenetsky formula to calculate the
    // number of digits

    double x = ((n*log10(n/e)+log10(2*pi*n)/2.0));

    return floor(x)+1;
}
*/


