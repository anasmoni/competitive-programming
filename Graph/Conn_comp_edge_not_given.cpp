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
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define Fill(G,v) memset(G,v,sizeof(G))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(G,b,c) max(G,max(b,c))
#define min3(G,b,c) min(G,min(b,c))

set<int> G[200020];
vector<int> res;
set<int> st;
///http://codeforces.com/contest/920/problem/E
int n, m;

int dfs(int i) {
	int sz = 1;
	for (set<int>::iterator it = st.begin(); it != st.end(); ) {
		if (G[i].count(*it) == 0) {
			int x = *it;
			st.erase(x);
			sz += dfs(x);
			it = st.lower_bound(x);
		} else {
			it++;
		}
	}
	return sz;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].insert(y);
		G[y].insert(x);
	}
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}
	while (st.size()) {
		int x = *st.begin();
		st.erase(x);
		res.push_back(dfs(x));
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i: res) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}
