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


int n , e;
const int MXN = 2e5 + 10;
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
	FOR(i, 0, n - 1) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	int mp = max_element(all(dis)) - dis.begin();
	dis.resize(n + 1, -1);
	dfs(mp, 0, 0);
	cout << *max_element(all(dis)) << nl;
}
