#include "bits/stdc++.h"
using namespace std;
#define int long long
using vi = vector<int>;
using vv = vector<vi>;
using pi = pair<int, int>;
using vp = vector<pi>;

#define nl 			"\n"
#define F 			first
#define S 			second
#define pb 			push_back
#define sz(x) 		(int)x.size()
#define read(x) 	int x; cin >> x
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<b;i++)
#define rev(i,a,b) 	for(int i=a;i>b;i--)
#define rdvr(x)    	for(auto &it :x) cin >> it

#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e18;
constexpr int MXN = 3e5 + 10;

struct node {
	int n, lzy;
	node(int n = 0LL) {
		this->n =  n;
		this-> lzy = 0LL;
	}
};

vi ar(MXN) ;
node tr[4 * MXN];

void push(int x , int l , int r) {
	if (tr[x].lzy) {
		tr[x].n += tr[x].lzy * (r - l + 1);
		if ( l != r) {
			tr[x << 1].lzy += tr[x].lzy;
			tr[x << 1 | 1].lzy += tr[x].lzy;
		}
		tr[x].lzy = 0LL;
	}
}
node merge(node& a , node &b) { return node(a.n + b.n); }
void build(int x, int l , int r) {
	if (l == r) {
		tr[x] = node(ar[l]);
		return;
	}
	int m =  (l + r) >> 1;
	build(x << 1, l, m); build(x << 1 | 1, m + 1, r);
	tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
void update(int x, int l , int r , int lq , int rq, int v) {
	push(x, l, r);
	if (rq < l || lq > r) return;
	if (lq <= l && r <= rq) {
		tr[x].lzy = v;
		push(x, l, r);
		return;
	}
	int m = (l + r) >> 1;
	update(x << 1, l, m, lq, rq, v); update(x << 1 | 1, m + 1, r, lq, rq, v);
	tr[x] = merge(tr[x << 1] , tr[x << 1 | 1]);
}
node qry(int x, int l , int r, int lq, int rq) {
	push(x, l, r);
	if (rq < l || lq > r) return node();
	if (lq <= l && r <= rq) return tr[x];
	int m = (l + r) >> 1;
	node a = qry(x << 1, l, m, lq, rq); node b = qry(x << 1 | 1, m + 1, r, lq, rq);
	return merge(a, b);
}


int32_t main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	read(n); read(q);
	rep(i, 0, n) cin >> ar[i];
	build(1, 0, n - 1);
	while (q--) {
		read(ch);
		if (ch == 1) {
			read(l); read(r); read(v);
			l--, r--;
			update(1, 0, n - 1, l, r, v);
		} else {
			read(k);
			k--;
			// cout << qry(1, 0, n - 1, k, k).n << nl;
		}
	}

}