#include<bits/stdc++.h>
using namespace std;

/**http://www.lightoj.com/volume_showproblem.php?problem=1093**/

#define MAX  100009

int maxim = 1e9,a[MAX];

struct Node{

    int mx,mn;

}tree[MAX*4];

void build(int idx , int lo , int hi)
{

    if(lo==hi)
    {
        tree[idx].mn = a[lo];
        tree[idx].mx = a[lo];

        return;
    }

    int mid = (lo+hi)/2;
    build(idx*2,lo,mid);
    build(idx*2+1,1+mid,hi);

    tree[idx].mn = min(tree[idx*2].mn,tree[idx*2+1].mn);
    tree[idx].mx = max(tree[idx*2].mx,tree[idx*2+1].mx);

}

int get_min(int idx , int lo , int hi , int l , int r)
{


    if(hi<l || lo>r)return maxim;

    if(l<=lo && hi<=r)return tree[idx].mn;

    int mid = (lo+hi)/2;

    int x = get_min(idx*2,lo,mid,l,r);
    int y = get_min(idx*2+1,1+mid,hi,l,r);

    return min(x,y);
}

int get_max(int idx , int lo , int hi , int l , int r)
{


    if(hi<l || lo>r)return -1;

    if(l<=lo && hi<=r)return tree[idx].mx;

    int mid = (lo+hi)/2;

    int x = get_max(idx*2,lo,mid,l,r);
    int y = get_max(idx*2+1,1+mid,hi,l,r);

    return max(x,y);
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1 ; tc<=t ; tc++)
    {
        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=1 ; i<=n ; scanf("%d",&a[i++]));

        build(1,1,n);
        int ans=-1,last;
        --q;

        for(int i=1 ; i<=n ; i++){
            last=i+q;
            if(last>n)last=n;

            int lo = get_min(1,1,n,i,last);
            int hi = get_max(1,1,n,i,last);
            ans = max(ans,hi-lo);

            if(last==n)break;

        }

        printf("Case %d: %d\n",tc,ans);

    }

    return 0;
}
