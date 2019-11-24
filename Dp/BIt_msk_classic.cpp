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
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))


/**https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1592**/
/**http://www.shafaetsplanet.com/planetcoding/?p=1357**/

int Set(int N,int pos){return N=N | (1<<pos);}

int reset(int N,int pos){return N= N & ~(1<<pos);}

bool check(int N,int pos){return (bool)(N & (1<<pos));}

int n;
int dp[(1<<13)+2];

int oka(int m, int i){

    if(i+2<12){

        if(check(m,i)&&check(m,i+1)&&!check(m,i+2)) return i+2;

        else if (!check(m,i)&&check(m,i+1)&&check(m,i+2)) return i;
    }
    return -1;
}

int ones(int mask){
    int cnt=0;
    while(mask){
        cnt+=(mask%2);
        mask = mask>>1;
    }
    return cnt;
}

bool scope(int mask){

    for(int i=0; i<12; i++){

        if(oka(mask,i)!=-1)return true;
    }

    return false;
}

int doit(int m,int r,int s,int k){
    m=reset(m,r);
    m=reset(m,k);
    m=Set(m,s);
    return m;
}

int call(int mask)
{

	if(!scope(mask)) return ones(mask);
	if(dp[mask]!=-1) return dp[mask];
	int mn=1<<28;

	for(int i=0;i<12;i++)
	{
        int idx = oka(mask,i);

        if(idx!=-1){
            int k = idx==i? i+2:i;


            int x  =  call(doit(mask,i+1,idx,k)) ;

            mn = min(mn,x);
        }

	}
    return dp[mask]=mn;
}
int main()
{
    int t;
    scn(t);

    while(t--){

		fill(dp,-1);

		string s;
        cin>>s;
        int mask=0,pw=1;

        for(int i=s.size()-1; i>=0; i--){
            mask += pw*(s[i]=='o');
            pw*=2;
        }
        //cout<<mask<<endl;
		int ret=call(mask);
        printf("%d\n",ret);
    }
	return 0;
}
