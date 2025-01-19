#include <bits/stdc++.h>
using namespace std;

// defines
using ll = long long;
using vi = std::vector<ll>;
// macros
#define nl "\n"
#define sz(a) (ll) a.size();
#define all(a) begin(a), end(a)
#define FOR(i, a, b) for (int i = a; i <= (int)b; i++)
#define ROF(i, a, b) for (int i = a; i >= (int)b; i--)

// " Is man one of God’s blunders or is God one of man’s blunder?? "

constexpr ll MOD = 998244353;
constexpr ll INF = 1e18;

ll bin_pow(ll b, ll e) {
  ll res = 1;
  while (e) {
    if (e & 1) res = (res * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return res;
}

int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
}