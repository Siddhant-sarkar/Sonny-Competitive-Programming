#include"bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define nl "\n"
#define pb push_back
#define all(x) begin(x),end(x)
#define TRA(x,a) for(auto &x : a)
#define FOR(i,a,b) for(int i = a;i<=b;i++)
//===================================================//

const int MXN = 2e5 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;

const int LOG = log2(MXN) + 5;
int n, dp[LOG][MXN], dep[MXN];
vector<int> adj[MXN];

void dfs(int u = 1, int p = 0, int d = 0)
{
	dep[u] = d;
	dp[0][u] = p;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, d + 1);
	}
}
int lift(int a, int k)
{
	for (int l = 0; l < LOG; l++) {
		if (k & (1 << l)) a = dp[l][a];
	}
	return a;
}
int lca (int n1 , int n2)
{
	n1 = lift(n1, dep[n1] - min(dep[n1], dep[n2]));
	n2 = lift(n2, dep[n2] - min(dep[n1], dep[n2]));
	if (n1 == n2) return n1;

	for (int l = LOG; l >= 0; l--) {
		if (dp[l][n1] != dp[l][n2]) {
			n1 = dp[l][n1];
			n2 = dp[l][n2];
		}
	}
	return dp[0][n1];
}
int dis(int n1 , int n2 )
{
	return dep[n1] + dep[n2] - 2 * dep[lca(n1, n2)]; // -> pretty much self explainatory.
}
signed main()
{
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b ;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for (int l = 1; l < LOG; l++) {
		for (int j = 1; j <= n; j++) {
			dp[l][j] = dp[l - 1][dp[l - 1][j]];
		}
	}
	cout << dis(1, 9) << endl;
	cout << lca(8, 12 ) << endl;
}