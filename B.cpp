#include "bits/stdc++.h"
using namespace std;

#define nl "\n"
#define int long long
constexpr int MOD = 1e9 + 7;
constexpr int INF  = 1e18;
const int N = 1e5 + 10;
#define all(s) s.begin(), s.end()
#define BANKAI ios_base::sync_with_stdio(false); cin.tie(nullptr)

#ifndef ONLINE_JUDGE
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

int n , e, cs = 0;
vector<int> adj[N], par(N), vis(N), ans;


void dfs(){

}
int32_t main()
{
	cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		int a, b ;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}
	if (!cs) {
		reverse(all(ans));
		for (int x : ans) cout << x << " ";
		return 0;
	} cout << "Sandro fails.\n";
}
