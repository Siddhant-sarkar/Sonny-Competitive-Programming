#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vv = vector<vi>;
using pi = pair<int, ll>;
using vp = vector<pi>;

#define nl 			"\n"
#define F 			first
#define S 			second
#define pb 			push_back
#define sz(x) 			(int)x.size()
#define read(x) 		ll x; cin >> x
#define all(s) 			s.begin(), s.end()
#define FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define ROF(i,a,b) 		for(int i=a;i>=b;i--)

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll MXN = 3e5 + 10;

struct node {
	ll minimum , cnt;
	node(ll x = INF ) {
		//--> default initializer value.
	}
};

node merge(node& a, node& b) {
	node rt;
	//--> merge logic.
	return rt;
}
struct SEGTREE {
	ll N;
	vector<node> tree;
	SEGTREE(ll n , vi& ar) {
		this-> N = n;
		tree = vector<node>(4 * N);
		build(ar, 1, 0, N - 1);
	}
	void build(vi& ar, ll x, ll l , ll r ) {
		if ( l == r) {
			tree[x] = node(ar[l]);
			return;
		}
		ll m = (l + r) / 2;
		build( ar, x << 1, l, m);
		build( ar, x << 1 | 1, m + 1, r);
		tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
	}
	void update(int x, int l , int r, int p , int v) {
		if ( p < l || p > r) return;
		if (  l == r ) {
			tree[x] = node(v);
			return;
		}
		int m = (l + r) / 2;
 		if (p <= m)update( x << 1 , l , m , p, v);
		else update(x << 1 | 1 , m + 1, r, p, v);
		tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
	}
	node query(int x , int l , int r, int lq , int rq) {
		if (rq < l || lq > r) return node();
		if ( lq <= l && r <= rq) return tree[x];

		int m = (l + r) / 2;
		node a = query(x << 1, l , m, lq, rq);
		node b = query(x << 1 | 1 , m + 1 , r, lq, rq);
		return merge(a, b);
	}
};


int32_t main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	ll n , q; cin >> n >> q;
	vi ar(n);
	FOR(i, 0, n - 1) cin >> ar[i];
	SEGTREE* s  = new SEGTREE(n, ar);
	while (q--) {
		ll a, b , c; cin >> a >> b >> c;
		if ( a == 1) {
			s->update( 1, 0, n - 1, b, c );
		} else {
			auto x = s->query(1, 0, n - 1, b, c - 1);
			cout << x.minimum  << " " << x.cnt << "\n";
		}
	}

}
