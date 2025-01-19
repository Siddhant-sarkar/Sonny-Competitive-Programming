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
  int n, e;
  cin >> n >> e;
  vector<vector<int>> graph(n + 1);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> vis(n + 1), p(n + 1);
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (auto v : graph[u]) {
      if (!vis[v]) {
        q.push(v);
        p[v] = u;
      }
    }
  }
}