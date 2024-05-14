#include<bits/stdc++.h>
using namespace std;

using ll 			= 		long long;
#define FOR(i,a,b)			for(ll i=a;i<=b;i++)

#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr ll MOD =  1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll N = 1e6+9;

vector<ll> a(N);
void harmonic(){
	for(int i=1;i< N ;i++){
		for(int j = i ;j<N;j+=i){
			a[j]+=i;
		}
	}
		
}



int32_t main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	harmonic();
	ll C ; cin >> C;
	FOR(i,1, C){
		ll K; cin >> K;
		 cout << a[K]-K << "\n";
	}
}

