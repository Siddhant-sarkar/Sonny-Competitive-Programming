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

int n, e;
vi adj[MXN], e1, e2;

void dfs(int u, int p) {
  e1.push_back(u);
  e2.push_back(u);
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      e1.push_back(u);  // --> type 1 .. // uselful for finding LCA
    }
  }
  e2.push_back(u);  // --> type 2 , more usefull
}
int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> n;
  e = n - 1;
  FOR(i, 0, e) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
}
