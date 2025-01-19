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

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

struct BINO {
  ll N;
  vector<ll> fact, inv;
  BINO(ll n) {
    N = n;
    fact = vector<ll>(N + 10);
    inv = vector<ll>(N + 10);
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    FOR(i, 2, N) fact[i] = (fact[i - 1] * i) % MOD;
    FOR(i, 2, N) inv[i] = bin_pow(fact[i], MOD - 2);
  }
  ll bin_pow(ll b, ll e) {
    ll res = 1;
    while (e) {
      if (e & 1) res = (res * b) % MOD;
      b = (b * b) % MOD;
      e /= 2;
    }
    return res % MOD;
  }
  ll fac(ll k) { return fact[k] % MOD; }
  ll nPR(ll n, ll r) { return (fact[n] * inv[n - r]) % MOD; }
  ll nCR(ll n, ll r) { return (((fact[n] * inv[n - r]) % MOD) * inv[r]) % MOD; }
};

int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
}
