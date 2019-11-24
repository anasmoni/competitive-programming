#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define MAX 100005

/**http://www.lightoj.com/volume_showproblem.php?problem=1164**/
/**basic http://www.shafaetsplanet.com/planetcoding/?p=1591*/

struct Node {
    lli prop, sum;
}tree[MAX*4];

void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

lli query(int node, int b, int e, int i, int j, lli carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    lli p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    lli p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1 ;tc<=t; ++tc){

        int n,q;
        scanf("%d%d",&n,&q);

        printf("Case %d:\n",tc);
        memset(tree,0,sizeof(tree)); /** ---------look----------*/

        while(q--){

            int x,y,z,v;
            scanf("%d",&z);

            if(z==0){
                scanf("%d%d%d",&x,&y,&v);
                update(1,1,n,1+x,1+y,v);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(1,1,n,1+x,1+y));
            }
        }
    }

    return 0;
}
