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


int main()
{
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int N , E ; cin >> N >> E;
	vector<vector<int>> graph(N + 1);
	FOR(i, 1, E) {
		int u, v ; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> vis(N + 1, -1);
	auto dfs  = [&] (auto && dfs , int u , int p, int c )->bool{
		if ( vis[u] != -1) return vis[u] == c ? 1 : 0;
		vis[u] = c;
		bool ans = 1;
		for (auto v : graph[u])
		{
			ans &= dfs(dfs , v , u, 1 - c);
		}
		return ans;
	};
	FOR(i, 1, N) {
		if ( vis[i] == -1) {
			if ( !dfs(dfs, i, 0, 1)) {
				// the graph cannot be bipartiite
				break;
			}
		}
	}
	// the graph is bibartitie
}

