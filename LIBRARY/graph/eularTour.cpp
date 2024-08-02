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


constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr int MXN = 3e5 + 10;

int n , e;
vi adj[MXN], e1, e2;

void dfs(int u , int p)
{
	e1.pb(u); e2.pb(u);
	for (auto v : adj[u] ) {
		if (v != p) {
			dfs(v, u);
			e1.pb(u); // --> type 1 .. // uselful for finding LCA
		}
	}
	e2.pb(u); // --> type 2 , more usefull
}
int32_t main()
{
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	cin >> n ; e = n - 1;
	rep(i, 0, e) {
		read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	dbg(e1, '\n' , e2);
}

