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
	ll n , s;
	scanf("%lld%lld", &n, &s);
	vi wt(n + 1);
	FOR(i, 1, n) scanf("%lld", &wt[i]);
	vector<vi> adj(n + 1);
	FOR(i, 1, n - 1) {
		ll u, v; scanf("%lld%lld", &u , &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

}