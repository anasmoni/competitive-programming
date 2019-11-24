#include<bits/stdc++.h>
using namespace std;


// Travelling salesman problem

typedef long long int lli;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
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
#define LL long long

///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1437

/// it's a little variation ..... basic at shanto sir's book page - 168(don't follow his code)

int check (int mask,int i)
{
    return (mask &(1<<i)); /// check , if the k'th bit is 1 (on)
}
int on(int mask,int k){
    return (mask|(1<<k));  /// set the k'th bit 1
}

LL  off(LL mask,int k){
    return (mask - (1<<k)); /// reset  k'th bit 0;
}

int toggle(int mask ,int k){
    return (mask^(1<<k));    /// toggle the k'th bit
}

int M[25][25],n; /// n = number of friends / node.........M[][] = dist between i & j
int memo[21][(1<<20)+5];
pair<int,int>P[21];

int dist(int x1,int y1,int x2,int y2)
{
    return (abs(x2-x1)+abs(y2-y1)); /// distance between two cells
}

int solve(int at,int mask)
{
     /// very important, friends == 0,1,2...n-1; so if mask+1 == 2^n...then
     /// back to the place where you began

    if(mask==(1<<n)-1){
        //cout<<at<<" "<<M[at][0]<<" ----\n";
        return M[at][0];
    }

    int &ret = memo[at][mask];

    if(ret!=-1) return ret;

    ret=inf;

    for(int i=0;i<n;i++)
    {
        if(check(mask,i) || i==at)continue; /// i'th bit on means friend i is already visited

        ret = min(ret, M[at][i] + solve(i,on(mask,i)));
    }
    return ret;
}
int main()
{
    //FRD;
    int i,j,t,cs=1,r,c;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&r,&c);

        cin>>P[0].first>>P[0].second;

        memset(memo,-1,sizeof memo);
        cin>>n;
        ++n;
        for(i=1;i<n;i++)scanf("%d %d",&P[i].first,&P[i].second);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                M[i][j]=dist(P[i].first,P[i].second,P[j].first,P[j].second);

        //CS;
        printf("The shortest path has length %d\n",solve(0,1));
    }
    return 0;
}

/*
1
10 10
1 1
4
2 3
5 5
9 4
6 5
*/

