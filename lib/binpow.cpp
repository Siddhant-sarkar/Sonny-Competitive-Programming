#include<bits/stdc++.h>
using namespace std;

using ll 			= 		long long;
#define FOR(i,a,b)			for(ll i=a;i<=b;i++)

#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr ll MOD =  998244353;
constexpr ll INF = 1e18;

ll bin_pow(ll b , ll e) {
	ll res = 1;
	while ( e) {
		if ( e & 1) res = (res * b) % MOD;
		b = (b * b) % MOD;
		e /= 2;
	}
	return res;
}

int32_t main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
}