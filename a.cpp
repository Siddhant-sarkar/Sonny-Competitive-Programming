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
#define read(x) 	int x; cin >> x
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define rev(i,a,b) 	for(int i=a;i>=b;i--)
#define rdvr(a,n)   vi a(n);for(auto &it :a) cin >> it

//I/O LIBRARY
#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b),0)...}
m1(pr) { cout << forward<T>(a);  m2(cout << " " << ); cout << "\n"; }
m1(re) { cin >> forward<T>(a); m2(cin >> ); }

// DEBUG HEADER FILE
#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif


void サンローラン_ドン() {

}
int32_t main() {
	clock_t tStart = clock();
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	rep(i, 1, t) {
		cerr << "Test " << i << nl;
		サンローラン_ドン();
	}
	cerr << "==============================";
	cerr << "\n>> Runtime : " << (double)(clock() - tStart) / CLOCKS_PER_SEC << nl;
}