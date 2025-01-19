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

// pascal triangle
vector<vector<ll>> nCR;
void pre() {
  ll k = 1e3;
  nCR = vector<vector<ll>>(k + 10, vector<ll>(k + 10));
  nCR[0][0] = 1LL;
  FOR(n, 1, k) {
    nCR[n][0] = nCR[n][n] = 1LL;
    FOR(r, 1, k) { (nCR[n][r] = nCR[n - 1][r] + nCR[n - 1][r - 1]) %= MOD; }
  }
}

void cp() {}

int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
  pre();
  cp();
}
