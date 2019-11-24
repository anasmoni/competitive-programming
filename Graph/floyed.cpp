#include <bits/stdc++.h>
using namespace std;
#define INF 900000

/**http://www.lightoj.com/volume_showproblem.php?problem=1174*/

int d[100][100];

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
        }
    }
}

void floyed(int n)
{

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int dist=d[i][k]+d[k][j];

                if(dist<d[i][j])d[i][j]=dist;
            }
        }
    }
}


int main()
{


    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++)
    {

        int n,r;
        scanf("%d %d",&n,&r);

        init(n);

        for(int i=0; i<r; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            d[u][v]=d[v][u]=1;
        }

        floyed(n);

        int s,dt;
        scanf("%d %d",&s, &dt);
            int ans=0;

        for(int i=0; i<n; i++)ans=max(ans,d[s][i]+d[i][dt]);

        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
