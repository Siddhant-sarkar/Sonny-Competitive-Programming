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

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  vector<bool> vis(n + 1);
  vector<int> par(n + 1, -1), top;

  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    vis[u] = 1;
    par[u] = p;
    for (auto v : graph[u]) {
      if (!vis[v] && v != p) {
        dfs(dfs, v, u);
      }
    }
    top.push_back(u);
  };
  FOR(i, 1, n) {
    if (!vis[i]) dfs(dfs, i, 0);
  }
  // topological sort
  reverse(begin(top), end(top));
}
