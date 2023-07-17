#include <bits/stdc++.h>
using namespace std;

// TYPE NAME ALIASEs
using ll			=		long long;
#define FOR(i,a,b)			for(ll i=(ll)a;i<=(ll)b;i++)

//DE-bug HEADER
#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define asdf(...);
#endif
//CONSTANTS
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
//HELPER
template<class T> inline T& cmin(T& a, const T& b) { if (b < a) a = b; return a; } // assign the minimum to the first
template<class T> inline T& cmax(T& a, const T& b) { if (a < b) a = b; return a; } // assign the maximum to the first
//-----------------------------------------------------------Veni,vidi,vici-----------------------------------------------------------//
//------------------------------------------------------I came ,I saw,I conquered-----------------------------------------------------//
void solve() {
ll n; cin >> n;

}

int32_t main() {
    clock_t tStart = clock();
    ll test = 1;
    scanf("%lld", &test);
    FOR(i, 1, test) {
#ifdef TSUKI
        cerr << "Test: " << i << "\n";
#endif
        solve();
    }
    cerr << ">> Runtime : " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n";
}