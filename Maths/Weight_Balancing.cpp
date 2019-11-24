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

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

///http://codeforces.com/problemset/problem/552/C

int main()
{
    int w,m;
    scn2(w,m);

    if(w<=3){
        cout<<"YES";
        return 0; /// any number can be made by power of 2 or 3
    }


    while(m){
        int md = m%w;
        if(md>1 && w-md>1){       /// sum of Wi (for sum i) = m + sum of Wk (for sum k!=j...may b 0)
            cout<<"NO";           /// if(md==1) then we would b able to add 1 in LHS
            return 0;             /// else if(md>1 && w-md==1) then we would b able to add 1  in RHS
        }
        m = (++m)/ w; /// why ++m ? ..... for cases like : 4 7
    }
    cout<<"YES";

    return 0;
}
