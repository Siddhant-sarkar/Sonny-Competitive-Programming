#include<bits/stdc++.h>
using namespace std;

using ll 			= 		long long;
#define sz(x)				ll(x.size())
#define all(x)				begin(x),end(x)
#define FOR(i,a,b)			for(ll i=a;i<=b;i++)

constexpr ll MOD 	=  		1e9 + 7;
constexpr ll INF 	= 		1e18;

vector<ll> seieve(2e6 + 10, 0);
vector<ll> primes;
void pre() {
	seieve[0] = seieve[1] = 1;
	for ( ll i = 2; i * i <= 2e5; i++) {
		if (!seieve[i] ) {
			primes.push_back(i);
			for ( ll j = i * i ; j <= 2e6; j += i)
				seieve[j] = 1 ;
		}
	}
}
void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	FOR(i, 0, n - 1) cin >> a[i];
	vector<ll> b;
	for (auto &k : a) {
		for (auto p : primes) {
			if ( k % p == 0) {
				b.push_back(p);
				while (k % p == 0) { k /= p; }
			}
		}
		if ( k > 1) {b.push_back(k); }
	}
	sort(all(b));
	FOR(i, 0, sz(b) - 2) {
		if (b[i] == b[i + 1]) {cout << "YES\n"; return;}
	}
	cout << "NO\n";
}


int32_t main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	pre();
	int t = 1; cin >> t;
	FOR(i, 1, t) {solve();}
}
