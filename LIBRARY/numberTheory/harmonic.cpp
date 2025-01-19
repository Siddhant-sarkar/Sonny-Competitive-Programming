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
constexpr ll N = 1e6 + 9;

void harmonic() {
  vector<ll> a(N);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      a[j]++;
    }
  }
  cout << " the numbers are \n";
  FOR(i, 1, 100) { cout << a[i] << " "; }
  cout << "\n";
}

int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
  harmonic();
}
