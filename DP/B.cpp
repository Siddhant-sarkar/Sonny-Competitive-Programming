#include "bits/stdc++.h"
using namespace std;
// TYPE NAME ALIASEs
using ll		=		unsigned long long;
using vi 		= 		vector<ll>;
using vv 		= 		vector<vi>;
using pi 		= 		pair<ll, ll>;
// DEFINE MACROS
#define nl 				"\n"
#define F 				first
#define S 				second
// MACROS
#define pb 				push_back
#define sz(x) 			(ll)x.size()
#define all(s)			s.begin(), s.end()
#define FRR(it, x)		for(auto &it :x)
#define FOR(i,a,b)		for(ll i=a;i<=b;i++)
#define ROF(i,a,b)		for(ll i=a;i>=b;i--)
// CUSTOM HASH
struct chash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};
// HELPER FUNCTION
ll fx_ceil(ll a, ll b) { return (a / b) + (a % b != 0); }
ll fx_lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll fx_pow (ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
//DEBUG HEADER FILE
#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif
//CONSTANTS
constexpr ll MOD = 1e9 + 7;
constexpr ll MXN = 4e4;
constexpr ll MX = 1e18;
//VARIADIC IO
#define io(...) ll __VA_ARGS__;read(__VA_ARGS__);
#define is(...) string __VA_ARGS__;read(__VA_ARGS__);
template <typename... T>void read(T &...args) {((cin >> args), ...);}
template <typename... T>void op(T... args) {((cout << args << " "), ...); cout << nl;}
template <typename... T>void ops(T... args) {((cout << args << " "), ...);}

void cp() {
	io( n , k);
	is(s);
	set<char>st;
	FOR(i, 1, k) {char c ; cin >> c; st.insert(c);}

	vi dp(n + 1);
	FOR(i, 1, n) {
		if ( st.count(s[i - 1])) {
			dp[i] = dp[i - 1] + 1;
		} else {dp[i] = 0;}
	}
	cout << accumulate(all(dp), 0LL) << nl;
}
int32_t main() {
	clock_t tStart = clock();
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	FOR(i, 1, t) { cp(); }
#ifdef TSUKI
	// cerr << ">> Runtime : " << (double)(clock() - tStart) / CLOCKS_PER_SEC << nl;
#endif
}