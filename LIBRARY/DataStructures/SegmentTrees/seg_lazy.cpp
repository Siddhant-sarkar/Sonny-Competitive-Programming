#include <bits/stdc++.h>
using namespace std;

// defines
using ll = long long;
using vi = std::vector<ll>;
// macros
#define nl "\n"
#define sz(a) (ll) a.size();
#define all(a) begin(a), end(a)
#define FOR(i, a, b) for (int i = a; i <= (int)b; i++)
#define ROF(i, a, b) for (int i = a; i >= (int)b; i--)

// " Is man one of God’s blunders or is God one of man’s blunder?? "

const int MXN = 2e5 + 10;
struct node {
  int n, lzy;
  node(int n = 0LL) {
    this->n = n;
    this->lzy = 0LL;
  }
};

vi ar(MXN);
node tr[4 * MXN];

void push(int x, int l, int r) {
  if (tr[x].lzy) {
    tr[x].n += tr[x].lzy * (r - l + 1);
    if (l != r) {
      tr[x << 1].lzy += tr[x].lzy;
      tr[x << 1 | 1].lzy += tr[x].lzy;
    }
    tr[x].lzy = 0LL;
  }
}
node merge(node& a, node& b) { return node(a.n + b.n); }
void build(int x, int l, int r) {
  if (l == r) {
    tr[x] = node(ar[l]);
    return;
  }
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
void update(int x, int l, int r, int lq, int rq, int v) {
  push(x, l, r);
  if (rq < l || lq > r) return;
  if (lq <= l && r <= rq) {
    tr[x].lzy = v;
    push(x, l, r);
    return;
  }
  int m = (l + r) >> 1;
  update(x << 1, l, m, lq, rq, v);
  update(x << 1 | 1, m + 1, r, lq, rq, v);
  tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
node qry(int x, int l, int r, int lq, int rq) {
  push(x, l, r);
  if (rq < l || lq > r) return node();
  if (lq <= l && r <= rq) return tr[x];
  int m = (l + r) >> 1;
  node a = qry(x << 1, l, m, lq, rq);
  node b = qry(x << 1 | 1, m + 1, r, lq, rq);
  return merge(a, b);
}

int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  FOR(i, 0, n) cin >> ar[i];
  build(1, 0, n - 1);
  while (q--) {
    int ch;
    cin >> ch;
    if (ch == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      l--, r--;
      update(1, 0, n - 1, l, r, v);
    } else {
      ll k;
      cin >> k;
      k--;
      // cout << qry(1, 0, n - 1, k, k).n << nl;
    }
  }
}