#include "bits/stdc++.h"
// #include "../bits/bug.hpp"
using namespace std;

constexpr int MXN = 100005;
int n , q;
int a[MXN];

struct node {
	int sum, mxr , lzy;
	node() {
		sum = 0;
		mxr = 0;
		lzy = 0;
	}
};
node merge(node a , node b) {
	node tmp;
	tmp.sum = a.sum + b.sum;
	tmp.mxr = max(a.mxr, b.mxr);
	return tmp ;
}
node tr[4 * MXN];
void push(int x , int l , int r) {
	if (tr[x].lzy) {
		tr[x].sum += tr[x].lzy * (r - l + 1);
		tr[x].mxr += tr[x].lzy;
		if (l != r) {
			tr[x << 1].lzy += tr[x].lzy;
			tr[x << 1 | 1].lzy += tr[x].lzy;
		}
		tr[x] .lzy = 0;
	}
}
void upd(int x, int l , int r , int lq , int rq , int v) {
	push(x , l , r);
	if (lq > r || l > rq) return;
	if ( lq <= l && r <= rq) {
		tr[x].lzy = v;
		push(x , l , r);
		return;
	}
	int m = (l + r) / 2;
	upd(x << 1, l, m , lq, rq, v); upd(x << 1 | 1 , m + 1, r, lq, rq, v);
	tr[x] = merge(tr[x << 1], tr[x << 1 | 1]) ;
}
node qry(int x , int l , int r, int lq , int rq) {
	push(x , l , r);
	if (lq > r || l  > rq) return node();
	if ( lq <= l && r <= rq) {return tr[x]; }
	int m = (l + r) >> 1;
	// return merge(qry(x << 1, l, m, lq, rq), qry(x << 1 | 1, m + 1, r, lq, rq));
	return merge(qry(x << 1, l, m, lq, rq), qry(x << 1 | 1, m + 1, r, lq, rq));
}

int32_t main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	upd(1, 0, 9, 4, 9, 5);
	upd(1, 0, 9, 0, 3, 7);
	node t = qry(1, 0, 9, 0, 9);
	cout << t.sum << " " << t.mxr << endl;
}
