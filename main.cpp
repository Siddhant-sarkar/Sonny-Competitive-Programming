#include "bits/stdc++.h"
using namespace std;

// TYPE NAME ALIASEs
#define int 			long long
using vi 		= 		vector<int>;
using vv 		= 		vector<vi>;
using pi 		= 		pair<int, int>;
using vp 		= 		vector<pi>;

// DEFINE MACROS
#define nl 				"\n"
#define F 				first
#define S 				second
#define pb 				push_back
#define sz(x) 			(int)x.size()
#define read(x) 		int x; cin >>x;
#define all(s) 			s.begin(), s.end()
#define loop(i,a,b) 	for(int i=a;i<=b;i++)
#define roop(i,a,b) 	for(int i=a;i>=b;i--)

// CUSTOM HASH
struct chash {
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		x ^= FIXED_RANDOM;
		return x ^ (x >> 16);
	}
};
int fx_ceil(int a, int b) { // ceil(a / b )
	return (a / b) + (a % b != 0);
}
int fx_lcm(int a, int b) {
	return a * b / gcd(a, b);
}

//DEBUG HEADER FILE
#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

//CONSTANTS
constexpr int MOD = 998244353;
constexpr int MXN = 2e5;
constexpr int MX = 1e18;

void サンローラン_ドン() {
	int n; cin >> n;
	cout << n << nl;
	cout << "this is not coloured in c++ string " << nl;
}
int32_t main() {
	clock_t tStart = clock();
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	loop(i, 1, t) {
		cerr << "\033[1;32m==>\tTest " << i << "\033[1;0m" << nl;
		サンローラン_ドン();
	}
	cerr << "\033[1;34m\n>> Runtime : " << (double)(clock() - tStart) / CLOCKS_PER_SEC << nl;
}
