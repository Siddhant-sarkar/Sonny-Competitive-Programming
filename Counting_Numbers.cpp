#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll a, b;
ll dp[20][2][2];
vector<ll> num;
int cnt = 0;

ll call2(ll pos, int f, ll l, ll v, string s) {
  if (pos == num.size()) {
    cout << s << endl;
    if (v) {
      cnt++;
    }
    return 0;
  }
  int LIM = f ? 9 : num[pos];
  for (ll dgt = 0; dgt <= LIM; dgt++) {
    ll nf = f;
    if (!f && dgt < LIM) nf = 1;
    ll nv = (!v ? 0 : (l != dgt));
    string ns = s;
    ns += ('0' + dgt);
    call2(pos + 1, nf, dgt, nv, ns);
  }
  return 0;
}
ll solve(ll a) {
  memset(dp, -1, sizeof(dp));
  num.clear();
  while (a) {
    num.push_back(a % 10);
    a /= 10;
  }
  reverse(begin(num), end(num));
  return call2(0, 0, -1, 1, "");
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> a >> b;
  cout << solve(b);
  cout << "cnt" << cnt << endl;
  // cout << solve(b) - solve(a - 1) << endl;
}