#include "bits/stdc++.h"
using namespace std;
#define int long long
using vi = vector<int>;
using vv = vector<vi>;
using pi = pair<int, int>;
using vp = vector<pi>;

#define nl 			"\n"
#define f 			first
#define s 			second
#define pb 			push_back
#define sz(x) 		(int)x.size()
#define read(x) 	int x; cin >> x
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<b;i++)
#define rev(i,a,b) 	for(int i=a;i>b;i--)
#define rdvr(x)    	for(auto &it :x) cin >> it

#ifdef tsuki
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18;
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