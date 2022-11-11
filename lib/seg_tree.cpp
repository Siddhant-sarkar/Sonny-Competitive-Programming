#include"bits/stdc++.h"
using namespace std;
#define int long long
constexpr int N =  2e5 + 10;

struct seg_tree {
	int sz;
	vector<int> tr;
	void init(int n) {
		sz = 1; while (sz < n) sz *= 2;
		tr.assign(2 * sz, 0LL);
	}
	void bld(vector<int>&a , int x , int lx , int rx) {
		if (rx - lx == 1) {
			if (lx < (int) a.size() ) {
				tr[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		bld(a, 2 * x + 1, lx, m); bld(a, 2 * x + 2, m, rx);
		tr[x] = tr[2 * x + 1] + tr[2 * x + 2];
	}
	void bld(vector<int> &a) {
		bld(a, 0, 0, sz);
	}
	void set(int i , int v, int x, int lx, int rx ) {
		if (rx - lx == 1) {
			tr[x] = v;
			return;
		}
		int m = (rx + lx) / 2;
		if (i < m) set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		tr[x] = tr[2 * x + 1] + tr[2 * x + 2];
	}
	void set(int i , int v) {
		set(i, v, 0, 0, sz);
	}
	int sum(int l , int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx ) return 0;
		if (lx >= l && rx <= r) return tr[x];
		int m = (lx + rx) / 2;
		return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);

	}
	int sum (int l , int r) {
		return sum(l, r, 0, 0, sz);
	}

};

int n , q;
int a[N];
signed main() {
	cin >> n >> q;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	seg_tree tr; tr.init(n); tr.bld(t);
	while (q--) {
		int qt; cin >> qt;
		if (qt == 1) {
			int i , v; cin >> i >> v;
			tr.set(i, v);
		} else {
			int l , r ; cin >> l >> r;
			cout << tr.sum(l, r) << "\n";
		}
	}
}