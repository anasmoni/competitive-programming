#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define A 1111111 /// a[i]<=10^6
#define BLOCK 400 /// ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

/***http://www.lightoj.com/volume_showproblem.php?problem=1188**/
/**
https://l.facebook.com/l.php?u=https%3A%2F%2Fblog.anudeep2011.
com%2Fmos-algorithm%2F&h=ATNGAZE24-FF8_3JsKkJK14jQ46XxCm4mYBX-
xvcCcKVVY7heGvVuSP-OMTaFtA8yNWJh9a6x8Plyospu8RfnYXRbCEXWaW7Nfp20HnUj8Hyy-ITEBKIqYNNBQAWjK3ehAcZ78EnHS8hgA
**/

struct node
{
    int L, R, i;
} q[N];

bool cmp(node x, node y)
{
    if(x.L/BLOCK != y.L/BLOCK)
    {
        /// different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    /// same block, so sort by R value
    return x.R < y.R;
}

void add(int position)
{
    cnt[a[position]]++;
    if(cnt[a[position]] == 1)
    {
        answer++;
    }
}

void remove(int position)
{
    cnt[a[position]]--;
    if(cnt[a[position]] == 0)
    {
        answer--;
    }
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++)
    {
        int n,m;
        scanf("%d%d", &n,&m);
        for(int i=0; i<n; i++)scanf("%d", &a[i]);

        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        answer=0;

        for(int i=0; i<m; i++)
        {
            scanf("%d%d", &q[i].L, &q[i].R);
            q[i].L--; /// it's an offline algo...so storing the queries
            q[i].R--;  /// as we working with 0 indexing but they are giving 1 indexing ...so --
            q[i].i = i; /// query number
        }

        sort(q, q + m, cmp);

        int currentL = 0, currentR = 0;
        for(int i=0; i<m; i++)
        {
            int L = q[i].L, R = q[i].R;
            //cout<<1+L<<" oka "<<R+1<<endl;

            while(currentL < L)
            {
                remove(currentL);
                currentL++;
            }
            while(currentL > L)
            {
                add(currentL-1);
                currentL--;
            }
            while(currentR <= R)
            {
                add(currentR);
                currentR++;
            }
            while(currentR > R+1)
            {
                remove(currentR-1);
                currentR--;
            }
            ans[q[i].i] = answer;
        }

        printf("Case %d:\n",tc);

        for(int i=0; i<m; i++)
            printf("%d\n", ans[i]);

    }

    return 0;
}
