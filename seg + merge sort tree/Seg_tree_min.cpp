#include<bits/stdc++.h>
using namespace std;

int a[100005],mn[500005],mx = 1e9;

/**http://www.lightoj.com/volume_showproblem.php?problem=1082**/

void build(int idx , int lo , int hi)
{

    if(lo==hi)
    {
        mn[idx] = a[lo];
        return;
    }

    int mid = (lo+hi)/2;
    build(idx*2,lo,mid);
    build(idx*2+1,1+mid,hi);

    mn[idx] = min(mn[idx*2],mn[idx*2+1]);

}

int query(int idx , int lo , int hi , int l , int r)
{


    if(hi<l || lo>r)return mx;

    if(l<=lo && hi<=r)return mn[idx];

    int mid = (lo+hi)/2;

    int x = query(idx*2,lo,mid,l,r);
    int y = query(idx*2+1,1+mid,hi,l,r);

    return min(x,y);
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
        memset(mn,0,sizeof(mn));
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--){
            int lo,hi;
            scanf("%d%d",&lo,&hi);
            printf("%d\n",query(1,1,n,lo,hi));
        }

    }


    return 0;
}
