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

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr int MXN = 3e5 + 10;

int n, q;
vi a(MXN);
// struct for segment Tree.
struct node {
  ll cs, psm, ssm, mss;
  node(ll x = 0) {
    cs = x;
    // psm = ssm = mss = x;
    psm = max(0LL, x);
    ssm = max(0LL, x);
    mss = max(0LL, x);
  }
} tr[4 * MXN];

// function to merge a Tree
node merge(node &a, node &b) {
  node rt;
  rt.cs = a.cs + b.cs;
  rt.psm = max(a.psm, a.cs + b.psm);
  rt.ssm = max(b.ssm, b.cs + a.ssm);
  rt.mss = max({a.mss, b.mss, a.ssm + b.psm});
  return rt;
}
// CRUD functions in segment Tree
void build(int x, int l, int r) {
  if (l == r) {
    tr[x] = node(a[l]);
    return;
  }
  int m = (l + r) / 2;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
void update(int x, int l, int r, int p, int v) {
  if (p < l || p > r) return;
  if (l == r) {
    tr[x] = node(v);
    a[l] = v;
    return;
  }
  int m = (l + r) / 2;
  if (p <= m)
    update(x << 1, l, m, p, v);
  else
    update(x << 1 | 1, m + 1, r, p, v);
  tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
node query(int x, int l, int r, int lq, int rq) {
  if (rq < l || lq > r) return node(0);
  if (lq <= l && r <= rq) return tr[x];

  int m = (l + r) / 2;
  node a = query(x << 1, l, m, lq, rq);
  node b = query(x << 1 | 1, m + 1, r, lq, rq);
  return merge(a, b);
}
int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  FOR(i, 0, n) cin >> a[i];

  build(1, 0, n - 1);                 // build the Tree
  update(1, 0, n - 1, 2, 8);          // update
  node x = query(1, 0, n - 1, 4, 9);  // query which return the node.
}
