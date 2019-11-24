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
#define N ten(6)+7

/// idea is n / p + n / p^2 + n / p ^3 + n / p ^ 4 until n / p ^ x is 0

bool check(lli p, lli nn , int cnt){

    lli pf=p;
    int av=0;
    while(cnt>0 && nn/pf){
        av += (nn/pf);
        pf *= p;
    }

    return (av>=cnt);
}

int main()
{
    ///freopen("debug.txt","w",stdout);

    lli n,m,M;

    while(scn2ll(n,m)==2){
        M=m;
        bool y = true;

        for(lli pf=2; y && pf*pf <= m; pf++){ /// look---- it's an O(root(n)/ln(root(n))) approach of finding prime factors....best approach
            int cnt=0;

            while(m%pf == 0){++cnt ; m /= pf;}

            if(!cnt)continue;

            y = check(pf,n,cnt);
        }

        if(m>1 && y) y = check(m,n,1); /// let m=6 then after the for loop ends m=3

        if(y)cout<<M<<" divides "<<n<<"!";
        else cout<<M<<" does not divide "<<n<<"!";
        cout<<endl;
    }

    return 0;
}
