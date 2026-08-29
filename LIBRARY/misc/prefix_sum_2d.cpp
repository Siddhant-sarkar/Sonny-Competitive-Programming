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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int N, M;
vector<vector<ll>> pre;

// 1-indexed. pre[i][j] = sum of ar[1..i][1..j]
void build(vector<vector<ll>>& ar) {
  pre.assign(N + 1, vector<ll>(M + 1, 0));
  FOR(i, 1, N)
  FOR(j, 1, M) pre[i][j] = ar[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
}

// sum of rectangle [x1,y1] -> [x2,y2] inclusive, 1-indexed
ll qry(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> N >> M;
  vector<vector<ll>> ar(N + 1, vector<ll>(M + 1));
  FOR(i, 1, N)
  FOR(j, 1, M) cin >> ar[i][j];

  build(ar);

  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << qry(x1, y1, x2, y2) << nl;
  }
}
