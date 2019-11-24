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

bool taken[200];
int n;
string s;

/**
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1717
***/

void permut(int idx , string t)
{

    if(idx>=n)
    {
        cout<<t<<endl;
        return;
    }


    for(int l=0; l<s.size(); l++)
    {
        if(sz(t) && t[sz(t)-1]>s[l])continue; /** s[l] is already done with s[i]>s[l] for any i */

        if(taken[l]==false)
        {
            taken[l]=true;

            permut(idx+1,t+s[l]);

            taken[l]=false;

            while(s[l]==s[l+1])l++;
        }
    }
}


int main()
{

    while(cin>>s>>n){

        Fill(taken,0);
        sort(atoz(s));

        permut(0,"");
    }

    return 0;
}

