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

constexpr int mod = 1e9 + 7;
constexpr ll inf = 1e18;
constexpr int MXN = 3e5 + 10;

int n , e ;
vi adj[MXN], dis ;

void dfs(int u, int p, int cnt)
{
	dis[u] = cnt;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, cnt + 1);
	}
}
int32_t main()
{
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	cin >> n;
	dis.resize(n + 1);
	rep(i, 0, n - 1) {
		read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
}