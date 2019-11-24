#include <bits/stdc++.h>
/**http://www.lightoj.com/volume_showproblem.php?problem=1141*/
#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long


using namespace std;

vector<int>v,factor;
bool prime[1100];

void sieve()
{
    prime[0]=1;
    for(int i=2; i<1100;)
    {
        v.pb(i);
        for(int j=i+i; j<1100; j+=i)
            prime[j]=1;
        for(++i;; i++)
            if(!prime[i])
                break;
    }
}

int d[1110];

bool visited[1110];

int bfs(int src, int dst)
{
    d[src]=0;
    queue<int>Q;
    Q.push(src);
    visited[src]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(u==dst) return d[u];
        int temp=u;
        if(prime[u]==0) continue;

        for(int i=0; temp>1; i++)
        {
            if(temp%v[i]==0)
            {
                factor.pb(v[i]);
                while(temp%v[i]==0)
                    temp/=v[i];
            }
        }

        for(int i=0; i<SZ(factor); i++)
        {
            int v=u+factor[i];
            if(v<=dst && !visited[v])
            {
                visited[v]=1;
                Q.push(v);
                d[v]=d[u]+1;
            }
        }

        factor.clear();
    }
    return -1;
}

void allclear()
{
    ms(visited,0);
    factor.clear();
    ms(d,0);
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    sieve();

    int t;
    sf(t);
    TEST_CASE(t)
    {
        allclear();
        int a,b;
        sff(a,b);
        PRINT_CASE;
            cout<<bfs(a,b)<<endl;
    }
    return 0;
}
