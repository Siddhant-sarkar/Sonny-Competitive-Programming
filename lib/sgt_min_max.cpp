#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long

#define pb push_back
#define all(s) s.begin(), s.end()
#define BAN__KAI cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
#include "../bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr int MOD = 1e9 + 7;
// constexpr int INF  = 100;
constexpr int INF  = 1e18;
const int N = 2e5 + 10;

int n , q ;
int ar[N];
struct seg_tree {
	int sz;
	vector<int> tr;
	void init(int n) {
		sz = 1; while (sz <= n)  sz *= 2;
		tr.assign(2 * sz, INF);
	}
	void bld(int n , int x , int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < n) {
				tr[x] = ar[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		bld(n, 2 * x + 1, lx, m); bld(n, 2 * x + 2, m, rx);
		tr[x] = min(tr[2 * x + 1], tr[2 * x + 2]);
	}
	void bld(int n ) {
		bld(n, 0, 0, sz);
	}
	void set(int i , int v, int x, int lx , int rx) {
		if (rx - lx == 1) {
			tr[x] = v;
			return;
		}
		int m = (rx + lx) / 2;
		if (i < m ) set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		tr[x] = min(tr[2 * x + 1], tr[2 * x + 2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, sz);
	}
	int qry(int l, int r, int x , int lx, int rx) {
		if (lx >= r || rx <= l) return INF;
		if (lx >= l && rx <= r ) return tr[x];
		int m = (lx + rx) / 2;
		return min(qry(l, r, 2 * x + 1, lx, m) , qry(l, r, 2 * x + 2, m, rx));
	}
	int qry(int l, int r) {
		return qry(l, r, 0, 0, sz);
	}
};
int32_t main() {
	BAN__KAI
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> ar[i];
	seg_tree tr;
	tr.init(n); tr.bld(n);
	while (q--) {
		int qt; cin >> qt;
		if (qt == 1) {
			int i ,  v; cin >> i >> v;
			tr.set(i, v);
		} else {
			int l , r ; cin >> l >> r;
			cout << tr.qry(l, r) << nl;
		}
	}


}
