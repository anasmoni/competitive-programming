#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define N 100002

set<int>tree[N];
int anc[N][20], subsz[N] , level[N] , ans[N] , parent[N];

void dfs0(int x, int par = -1)
{
    for(auto it = tree[x].begin() ; it != tree[x].end(); it++){

        if(*it == par) continue;

        anc[*it][0] = x;
        level[*it] += level[x] + 1;

        dfs0(*it,x);
    }
}

void init_LCA(int n)
{
    dfs0(1);

    for(int i=0; i<=n; i++) ans[i] = ten(9);

    int lgn = (int)(log(n)/log(2))+1;

    for(int j = 1; j<=lgn; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

int LCA(int p, int q)
{
    int tmp, log, i;

    if (level[p] < level[q]) swap(p,q);

    for (log = 1; (1 << log) <= level[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
    {

        if (level[p] - (1 << i) >= level[q]) p = anc[p][i];
    }

    if (p == q) return p;

    for (i = log; i >= 0; i--)
    {

        if (anc[p][i] != 0 && anc[p][i] != anc[q][i])
        {
            p = anc[p][i];
            q = anc[q][i];
        }
    }

    return anc[p][0];
}

int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[LCA(u,v)];
}

/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	subsz[u]=1;
	nn++;

	for(auto it=tree[u].begin(); it != tree[u].end(); it++){

		if(*it != p)
		{
			dfs1(*it,u);
			subsz[u] += subsz[*it];
		}
	}
}
int dfs2(int u,int p)
{
	for(auto it = tree[u].begin(); it != tree[u].end(); it++){

		if(*it!=p && subsz[*it]>(nn/2)){

            return dfs2(*it,u);
		}
	}
	return u;
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);

	int centroid = dfs2(root,root);

	if(p==-1)p=centroid;

	parent[centroid]=p;

	for(auto it=tree[centroid].begin(); it != tree[centroid].end(); it++)
	{
		tree[*it].erase(centroid);
		decompose(*it,centroid);
	}
}
/*----------------- Handle the Queries -----------------*/

void update(int u)
{
	int x = u;
	while(1)
	{
		ans[x] = min(ans[x],dist(x,u));
		if(x==parent[x])
			break;
		x = parent[x];
	}
}
int query(int u)
{
	int x = u;
	int ret=ten(9);

	while(1)
	{
		ret = min(ret,dist(u,x) + ans[x]);

		if(x==parent[x]) break;

		x = parent[x];
	}
	return ret;
}

int main()
{

    int n , m;
    scn2(n,m);

    for(int i=1; i<n; i++){
        int u,v;
        scn2(u,v);
        tree[u].insert(v);
        tree[v].insert(u);
    }

    init_LCA(n);
    decompose(1,-1);
    update(1);

    while(m--){

        int t , node;
        scn2(t,node);

        if(t == 1){
            update(node);
        }
        else printf("%d\n",query(node));
    }

    return 0;
}
