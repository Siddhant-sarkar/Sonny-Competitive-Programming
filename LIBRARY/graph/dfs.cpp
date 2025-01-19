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

constexpr int mod = 1e9 + 7;
constexpr ll inf = 1e18;
constexpr int MXN = 3e5 + 10;

int n, e;
vi adj[MXN], dis;

void dfs(int u, int p, int cnt) {
  dis[u] = cnt;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, cnt + 1);
  }
}
int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> n;
  dis.resize(n + 1);
  FOR(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 0);
}