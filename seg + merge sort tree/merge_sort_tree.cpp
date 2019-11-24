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

vector<int>tree[5*N];
int a[N],n,q;

lli mx=-1e11;
lli mn=1e11;
map<int,int>idx;

/** http://www.spoj.com/problems/MKTHNUM/ **/
/** see merge sort tree from codechef**/

void build_tree( int cur, int l, int r )
{
    if( l==r )
    {
        tree[cur].pb( a[l] );
        return ;
    }

    int mid = (r+l)/2;
    int left = 2*cur;
    int right =  2*cur+1;

    build_tree(left, l, mid );  // Build left tree
    build_tree(right, mid+1, r );   // Build right tree

    int i=0,j=0;
    int md=tree[left].size();
    int hi=tree[right].size();

    /**merging two sorted vector**/

    for(int kk=0 ; kk<hi+md ; kk++)
    {
        if(i==md)tree[cur].pb(tree[right][j++]);

        else if(j==hi)tree[cur].pb(tree[left][i++]);

        else if(tree[left][i]<tree[right][j])tree[cur].pb(tree[left][i++]);

        else tree[cur].pb(tree[right][j++]);
    }
}

int query( int cur, int l, int r, int x, int y, int k)
{
    if( r < x || l > y )
    {
        return 0; //out of range
    }
    if( x<=l && r<=y )
    {
        /**finding min & max of this segment for binary search**/
        mx = max(mx,(lli)tree[cur][tree[cur].size()-1]);
        mn = min(mn,(lli)tree[cur][0]);

        /** Binary search over the current sorted vector to find elements smaller than K*/
        return upper_bound(atoz(tree[cur]),k)-tree[cur].begin();
    }

    int mid=(r+l)/2;

    return query(2*cur,l,mid,x,y,k)+query(2*cur+1,mid+1,r,x,y,k);
}

int main()
{
    scn2(n,q);


    for(int i=1 ; i<=n; i++){
        scn(a[i]);
        idx[a[i]]=i;
    }


    build_tree(1,1,n);

    while(q--)
    {

        int lo,hi,k;
        scn2(lo,hi);
        scn(k);         /** kth smallest element in this range*/

       // printf("oka-> %d\n",query(1,1,n,lo,hi,k));
        int temp = query(1,1,n,lo,hi,k);
        int l=(int)mn,h=(int)mx;
        int mid;

         while(l<=h){

             mid = (l+h)/2;

             temp = query(1,1,n,lo,hi,mid);

             if(temp == k && (idx[mid]>=lo && idx[mid]<=hi)){ /**if mid axist in array**/
                printf("%d\n",mid);
                break;
             }
             else if(temp<k)l=mid+1;
             else h=mid-1; /** all elements are distinct ...so , if mid isn't in array do it too**/
         }
    }

    return 0;
}

