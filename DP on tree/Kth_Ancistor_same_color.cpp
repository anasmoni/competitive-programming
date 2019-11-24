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
#define N 1000007

/***
problem desc:
    given a tree with colored nodes....find the kth closest ancestor of same color for each node....if imposs print -1
**/

/**u must see kth Ancestor first**/
int color[N];
vector<int>V[N];
//int vex[N];
map<int,int>last; /** last parent with color last.first **/
int p[N][25]= {{0}};


void dfs(int x, int par)
{


    p[x][0] = last[color[x]];

    last[color[x]] = x;

   // vex[x] = ++cur[color[x]];


    for(auto u:V[x])
    {
        if(par==u)continue;
        dfs(u,x);
    }
   // cur[color[x]]--;
    last[color[x]] = p[x][0];
}

int main()
{
    int n,k;
    scn2(n,k);
  //  int cur[n+3];

    for(int i=1 ; i<=n; i++)
    {
        scn(color[i]);
       // cur[color[i]]=0;
    }


    for(int i=1 ; i<n; i++)
    {
        int x,y;
        scn2(x,y);
        V[x].pb(y);
        V[y].pb(x);
    }

    dfs(1,-1);

    int lgn = (int)(log(n)/log(2))+1;  /**10 based log....but we need 2 base log ....so...**/

    for(int j = 1; j<=lgn; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            p[i][j] = p[p[i][j-1]][j-1];

            /**
            say,
                    y =  2^(j-1) th anc of x
                    z =  2^(j-1) th anc of y
                    then,
                    z =  2^j th anc of x
            **/
        }
    }

    for(int xx=1 ; xx<=n; xx++)
    {
        int j = 0;
        int y=k;
        int x=xx;
        if(!k){
            printf("-1 ");
            continue;
        }
        while(y>0)
        {
            if(y&1)x = p[x][j];
            y = y>>1; /** div by 2 */
            j++;
        }
        if(!x)x=-1;
        printf("%d ",x);
    }


    return 0;
}
/**
10 2
1 1 2 1 1 2 2 1 1 1
1 2
1 3
2 7
2 4
4 5
4 6
3 8
8 10
8 9


**/
