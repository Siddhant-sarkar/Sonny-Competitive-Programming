#include "bits/stdc++.h"
using namespace std;
#define int long long
using vi = vector<int>;
using vv = vector<vi>;
using pi = pair<int, int>;
using vp = vector<pi>;

#define nl 			"\n"
#define F 			first
#define S 			second
#define pb 			push_back
#define sz(x) 		(int)x.size()
#define read(x) 	int x; cin >> x
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<b;i++)
#define rev(i,a,b) 	for(int i=a;i>b;i--)
#define rdvr(x)    	for(auto &it :x) cin >> it

#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e18;
constexpr int MXN = 3e5 + 10;

int n , e;
vi adj[MXN], e1, e2;

void dfs(int u , int p) {
	e1.pb(u); e2.pb(u);
	for (auto v : adj[u] ) {
		if (v != p) {
			dfs(v, u);
			e1.pb(u); // --> type 1 .. // uselful for finding LCA
		}
	}
	e2.pb(u); // --> type 2 , more usefull
}
int32_t main() {
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

