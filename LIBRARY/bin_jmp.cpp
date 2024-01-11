#include "bits/stdc++.h"
using namespace std;

#define int long long
#define nl cout <<"\n"

const int MXN = 2e5 + 10;
const int INF = 1e18 + 10;
const int MOD = 1e9 + 7;


const int LOG = log2(MXN) + 5;
int n, dp[LOG][MXN];
vector<int> adj[MXN];

// using dfs to set dp[0][i] initial parents
void dfs(int u = 1 , int p = 0) {
	dp[0][u] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}

signed main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	// using DP to create a sparse table structure
	for (int l = 1; l < LOG; l++) {
		for (int j = 1; j <= n; j++) {
			dp[l][j] = dp[l - 1][dp[l - 1][j]];
		}
	}

	int node, k;
	cin >> node >> k;

	// using the set bits to jump from nodes to nodes
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) node = dp[i][node];
	}

	cout << node;
	nl;
}
