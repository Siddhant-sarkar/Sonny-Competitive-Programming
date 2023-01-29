#include "bits/stdc++.h"
using namespace std;
#define int         long long
using vi    =       vector<int>;
using vv    =       vector<vi>;
using pi    =       pair<int, int>;
using vp    =       vector<pi>;

#define nl          "\n"
#define F           first
#define S           second
#define pb          push_back
#define sz(x)       (int)x.size()
#define read(x)     int x; cin >> x
#define all(s)      s.begin(), s.end()
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define rev(i,a,b)  for(int i=a;i>=b;i--)
#define rdvr(x)     for(auto &it :x) cin >> it

// #ifdef TSUKI
// #include "bits/bug.hpp"
// #else
// #define dbg(...)
// #endif

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e18;
constexpr int MXN = 2e5 + 10;

int dp[301][100000];
void サンローラン_ドン() {
    int n; cin >> n;
    vi a(n); rdvr(a);
    int sum = accumulate(all(a), 0LL);
    if (sum % 2) {cout << -1 << nl; return;}
    sum >>= 1;

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n ; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i - 1] ) dp[i][j] |= dp[i - 1][j - a[i - 1]] ;
            }
        }
    }
    if (!dp[n][sum]) {cout << -1 << nl; return;}
    vi psf;
    for (int i = n; i >= 1 && sum > 0; i--) {
        if (dp[i - 1][sum] == 1) continue;
        else {
            psf.push_back(i);
            sum -= a[i - 1];
        }
    }
    int vela;
    sort(all(psf));
    vp bpt1, bpt2, ans;
    for (int i = 1; i <= n; i++ ) {
        if (binary_search(all(psf) , i )) { bpt1.pb({a[i - 1], i}); }
        else bpt2.pb({a[i - 1], i});
    }

    while (sz(bpt1)) {
        auto& [a1, i1] = bpt1.back(); bpt1.pop_back();
        auto& [a2, i2] = bpt2.back(); bpt2.pop_back();
        // dbg(a1, a2);
        int k = min(a1, a2);
        a1 -= k; a2 -= k;
        if (a1) bpt1.pb({a1, i1});
        if (a2) bpt2.pb({a2, i2});
        ans.pb({i1, i2});

    }
    cout << sz(ans) << nl;
    for (auto [a, b] : ans)
        cout << a << " " << b << nl;
}
int32_t main() {
    cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        サンローラン_ドン();
    }
}