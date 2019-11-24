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
#define N 100005

// explanation
/**https://www.hackerrank.com/challenges/kth-ancestor/editorial */


int p[100000][40]={{0}}; /** p[i][j] = 2^j th Ancistor of i */
int a[100005],isnode[100005];

int main ()
{

    int q,ch,x,y,t;
    scanf("%d",&t);

    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(isnode,0,sizeof(isnode));

        int i,n,j;
        scanf("%d",&n);

        for(i = 0;i < n;i++)
        {
            scanf("%d %d",&x,&y);

            a[i] = x; /**as a tree x has exactly 1 parent*/
            isnode[x] = 1;
            p[x][0] = y; /** y is parent of x...so y is 2^0 == 1 th ancistor of x **/
        }

        int lgn = (int)(log(n)/log(2))+1;  /**10 based log....but we need 2 base log ....so...**/

        for(j = 1;j<=lgn;j++)
        {
            for(i = 0;i < n;i++)
            {
                p[a[i]][j] = p[p[a[i]][j-1]][j-1];

                /**
                say,
                        y =  2^(j-1) th anc of x
                        z =  2^(j-1) th anc of y
                        then,
                        z =  2^j th anc of x
                **/
            }
        }

        scanf("%d",&q);

        for(i = 0;i < q;i++)
        {
            scanf("%d",&ch);

            if(ch == 0) //Add an edge
            {
                scanf("%d %d",&x,&y); /** y is not in tree....but x is;  x = parent of y **/
                isnode[y] = 1;
                p[y][0] = x;
                j = 0;

                while(j<=lgn)
                {
                    p[y][j+1] = p[p[y][j]][j]; /** as y is new in tree...so store it's ances*/
                    j++;
                }
            }
            else if(ch == 1) //Remove an edge
            {
                scanf("%d",&x);
                isnode[x] = 0;

                for(j = 0;j <= lgn;j++) p[x][j] = 0;
            }
            else
            {
                scanf("%d %d",&x,&y); /** print  y th anc of x **/
                j = 0;

                while(y>0)
                {
                    if(y&1)x = p[x][j];
                    y = y>>1; /** div by 2 */
                    j++;
                }
                printf("%d\n",x);
            }
        }
    }
    return 0;
}
