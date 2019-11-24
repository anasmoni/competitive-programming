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

/**
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=618
**/

int n,len,x, gf[11][11], vis[12] , ans[12] , flag=0;

void dfs(int idx, int cnt){

    if(cnt==len){

        cout<<"(";
        for(int i=0; i<len ;i++)cout<<ans[i]<<",";
        cout<<ans[len]<<")\n";
        flag=1;
        return;
    }

    for(int i=1; i<=n; i++){

        if(gf[idx][i] && vis[i]==0){

            ans[cnt+1]=i;
            vis[i]=1;
            dfs(i,cnt+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int f=0;

    while(scn2(n,len)==2){

        if(f++)cout<<endl;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)scn(gf[i][j]);
            vis[i]=0;
        }
        flag=0;
        ans[0]=vis[1]=1;
        dfs(1,0);
        if(!flag) printf("no walk of length %d\n", len);
        scn(x);

    }

    return 0;
}
