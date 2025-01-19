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

struct SIEVE {
  vector<ll> sieve;
  vector<ll> primes;
  SIEVE(ll N) {
    sieve = vector<ll>(N + 10);
    sieve[0] = sieve[1] = 1;
    for (ll i = 2; i <= N; i++) {
      if (!sieve[i]) {
        // sieve[i] = i;
        primes.push_back(i);
        for (ll j = i * i; j <= N; j += i) sieve[j] = 1;
        // for ( ll j = i * i ; j <= N; j += i) sieve[j] = i ;
      }
    }
  }
  set<ll> get(ll x) {
    set<ll> r;
    while (x != 1) {
      r.insert(sieve[x]);
      x /= sieve[x];
    }
    return r;
  }
};

int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
  SIEVE *s = new SIEVE(2e6);
}
