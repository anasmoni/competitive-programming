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
#define N 50007
#define NN ten(5)

///UVa 10820 Send a Table

vector<int>prime;
bool vis[NN+5];
lli ans[N];

void Sieve()
{
    for (int p=2; p*p<=NN; p++)
    {
        if (vis[p])continue;

        for (int i=p*p; i<=NN; i += p) vis[i] = true;

    }

    prime.pb(2);
    for (int p=3; p <= NN; p += 2)
       if (vis[p] == false) prime.pb(p);
}


lli EulerPhi(lli n){

    lli ret = n;

    for(auto pf : prime){ /// prime factorixation

        if((pf*pf) > n)break;

        if(n%pf == 0) ret -= ret/pf;

        while(n%pf == 0) n /= pf;
    }
    if(n>1)ret -= ret/n;

    return ret; /// number of coprimes of n (coprime<n)
}

void PreCalc(){

    ans[1]=1;

    for(int i=2; i<N; i++){
        ans[i] = 2LL*EulerPhi((lli)i);
    }

    for(int i=2; i<N; i++)ans[i] += ans[i-1];
}

int main()
{
    ///freopen("debug.txt","w",stdout);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    Sieve();

    PreCalc();

    int n;
    while(scn(n)==1){
        if(n==0)break;
        cout<<ans[n]<<endl;
    }


    return 0;
}
