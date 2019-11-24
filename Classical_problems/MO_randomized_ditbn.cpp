#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+7;
const int block_size = 600;
int a[N], res[N], freq[N];

struct data {
	int l, r, k, id;
	bool operator < (const data &p) {
		if(l / block_size != p.l / block_size) return l < p.l;
		return ((l/block_size) & 1 ? (r < p.r) : (r > p.r));
	}
} qu[N];

inline void add(int idx) {
	++freq[a[idx]];
}

inline void remove(int idx) {
	--freq[a[idx]];
}

random_device rd;
mt19937 ran(rd());

int randomize(int l, int r, int k) {
	uniform_int_distribution<int> dist(l, r);

	int thr = (r-l+1) / k;
	int res = INT_MAX;
	for(int i=0; i<80; ++i) {
		int cur = a[dist(ran)];
		if(freq[cur] > thr) res = min(res, cur);
	}

	return (res == INT_MAX ? -1 : res);
}

///https://codeforces.com/contest/840/problem/D

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<q; ++i) {
		cin >> qu[i].l >> qu[i].r >> qu[i].k;
		qu[i].id = i;
		--qu[i].l, --qu[i].r;
	}

	sort(qu, qu+q);
	int cur_l = 0, cur_r = -1;
	for(int i=0; i<q; ++i) {
		auto x = qu[i];
		while(cur_l > x.l) {
			--cur_l;
			add(cur_l);
		}
		while(cur_r < x.r) {
			++cur_r;
			add(cur_r);
		}
		while(cur_l < x.l) {
			remove(cur_l);
			++cur_l;
		}
		while(cur_r > x.r) {
			remove(cur_r);
			--cur_r;
		}
		res[x.id] = randomize(x.l, x.r, x.k);
	}

	for(int i=0; i<q; ++i) cout << res[i] << "\n";

	return 0;
}
