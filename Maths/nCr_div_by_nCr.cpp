#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
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
#define N ten(5)

///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1316-------------------10375 - Choose and divide

/// given p,q,r,s all <= 10000 and p>=q and r>=s
/// find pCq / rCs     with 5 digits of precision  .....it is guarented that ans <= 10^8

vector<int>prime;
bool vis[N+7];

void Sieve()
{
    for (int p=2; p*p<=N; p++)
    {
        if (vis[p])continue;

        for (int i=p*p; i<=N; i += p) vis[i] = true;

    }

    prime.pb(2);
    for (int p=3; p <= N; p += 2)
       if (vis[p] == false) prime.pb(p);
}

int main()
{
    ///freopen("debug.txt","w",stdout);


    int p,q,r,s;
    Sieve();
    cout<<setprecision(5)<<fixed; /// if we dont do that some digits will be ignored after decimal point

    while(scn2(p,q)==2){

        scn2(r,s);
        unsigned long long nom,denom;
        nom = denom = 1;
        long double ans=1.0;

        for(auto x : prime){

            if(x > max(p,r))break;

            int nom_pow = 0 , pf = x , denom_pow = 0;

            while(p/pf || (r-s)/pf || s/pf){

                nom_pow += p/pf;
                nom_pow += (r-s)/pf;
                nom_pow +=  s/pf;

                pf *= x;
            }
            pf = x;

            while(q/pf || (p-q)/pf || r/pf){

                denom_pow += q/pf;
                denom_pow += (p-q)/pf;
                denom_pow +=  r/pf;

                pf *= x;
            }

            if(denom_pow >= nom_pow){

                denom_pow -= nom_pow;

                while(denom_pow--) denom *= x;
            }
            else{
                nom_pow -= denom_pow;

                while(nom_pow--) nom *= x;
            }
            ans *= ((nom*1.0)/(denom*1.0)); /// final nom and denom can b huge so ....
            nom = denom = 1;
        }
        cout<<ans<<endl;
        //cout<<((nom*1.0)/(denom*1.0))<<endl;
        //" "<<nom<<" "<<denom<<endl;
    }

    return 0;
}
