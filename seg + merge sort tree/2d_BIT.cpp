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
#define Last(i) ( (i) & (-i) )
#define MOD 1000000007
#define N 1008

int XY[N+8][N+8] , taken[N+8][N+8];

int query(int x, int y)
{
    int res=0;

    while(x>0)
    {
        int idx = y;
        while(idx>0)
        {
            res += XY[x][idx];
            idx -= Last(idx);
        }

        x -= Last(x);
    }
    return res;
}

void update(int x, int y)
{
    while(x<=N)
    {
        int idx = y;
        while(idx<=N)
        {

            XY[x][idx]++;
            idx += Last(idx);
        }
        x += Last(x);
    }
}


int main()
{
    //freopen("debug.txt","w",stdout);
    int t;
    scn(t);

    for(int cs=1; cs<=t; cs++)
    {

        int n,c,x1,x2,y1,y2;
        Fill(XY,0);
        Fill(taken,0);
        scn(n);
        printf("Case %d:\n",cs);

        while(n--)
        {
            scn(c);
            if(c==0)
            {
                scn2(x1,y1);
                x1++;
                y1++;
                if(taken[x1][y1]==0){
                    update(x1,y1);
                    taken[x1][y1]=1;
                }
            }
            else
            {
                scn3(x1,y1,x2);
                scn(y2);
                x1++;
                x2++;
                y1++;
                y2++;

                int x = query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);

                printf("%d\n",x);
            }
        }
    }
}
