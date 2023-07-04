#include<bits/stdc++.h>
using namespace std;

using ll 			= 		long long;
#define sz(x)				ll(x.size())
#define all(x)				begin(x),end(x)
#define FOR(i,a,b)			for(ll i=a;i<=b;i++)

constexpr ll MOD 	=  		1e9 + 7;
constexpr ll INF 	= 		1e18;

struct SEIEVE {
	vector<ll> seieve;
	vector<ll> primes;
	SEIEVE(ll N) {
		seieve = vector<ll> (N + 10);
		seieve[0] = seieve[1] = 1;
		for ( ll i = 2; i * i <= N; i++) {
			if (!seieve[i]) {
				primes.push_back(i);
				for ( ll j = i * i ; j <= N; j += i) seieve[j] = 1 ;
			}
		}
	}
};



int32_t main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	SEIEVE *s = new SEIEVE(2e6);
	for (auto x : s->primes)
		cout << x << " ";
	cout << " \n";
}
