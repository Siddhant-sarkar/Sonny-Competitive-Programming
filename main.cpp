#include "bits/stdc++.h"
using namespace std;

// TYPE NAME ALIASEs
#define int 		long long
using vi 	= 		vector<int>;
using vv 	= 		vector<vi>;
using pi 	= 		pair<int, int>;
using vp 	= 		vector<pi>;

// DEFINE MACROS
#define nl 			"\n"
#define F 			first
#define S 			second
#define pb 			push_back
#define sz(x) 		(int)x.size()
#define read(x) 	int x; cin >>x;
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define rev(i,a,b) 	for(int i=a;i>=b;i--)
#define rdvr(a,n)   vi a(n);for(auto &it :a) cin >> it

//DEBUG HEADER FILE
#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

//CONSTANTS
constexpr int MOD = 998244353;
constexpr int N = 2e5;

void サンローラン_ドン() {
	read(n); read(m);

	dbg(n, m)
}




int32_t main() {
	clock_t tStart = clock();
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	rep(i, 1, t) {
		// cerr << "==>\tTest " << i << nl;
		サンローラン_ドン();
	}
	cerr << "\n>> Runtime : " << (double)(clock() - tStart) / CLOCKS_PER_SEC << nl;
}