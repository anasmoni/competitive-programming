#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 10;

/// https://codeforces.com/contest/739/problem/B
/// given a tree , edge weighted and nodes r weighted. for every node v find count of such u such that
/// u in the subtree rooted at v and dist(v,u) <= val[u];

vector<int> adj[maxn], cost[maxn];
int in[maxn], out[maxn], idx;
ll a[maxn], dist[maxn], t[maxn];

void dfs(int u, int par) {
	t[idx] = dist[u] - a[u];
	in[u] = idx++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i], w = cost[u][i];
		if(v == par) continue;
		dist[v] = dist[u] + w;
		dfs(v, u);
	}
	out[u] = idx-1;
}

vector<ll> tree[maxn << 2];

void build(int node, int l, int r) {
	if(l == r) {
		tree[node].push_back(t[l]);
		return;
	} int mid = l + r >> 1;
	build(node<<1, l, mid);
	build(node<<1|1, mid+1, r);
	merge(tree[node<<1].begin(), tree[node<<1].end(),
		tree[node<<1|1].begin(), tree[node<<1|1].end(),
		back_inserter(tree[node]));
}

int query(int node, int l, int r, int i, int j, ll k) {
	if(r < i || l > j) return 0;
	if(i <= l && r <= j) {
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	} int mid = l + r >> 1;
	return query(node << 1, l, mid, i, j, k) + query(node << 1|1, mid + 1, r, i, j, k);
}

int main(int argc, char const *argv[]) {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(int i = 1; i < n; i++) {
		int p, w; scanf("%d %d", &p, &w);
		adj[p].push_back(i+1);
		cost[p].push_back(w);
	}
	dfs(1, 0);
	build(1, 0, idx - 1);

	for(int i = 1; i <= n; i++)
		printf("%d ", query(1, 0, idx-1, in[i]+1, out[i], dist[i]));
}
