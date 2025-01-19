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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<vector<ll>> MatrixExpo(vector<vector<ll>> A, ll b) {
  ll N = A.size();
  vector<vector<ll>> ans(N, vector<ll>(N));
  auto mult = [&](vector<vector<ll>> u,
                  vector<vector<ll>> v) -> vector<vector<ll>> {
    FOR(i, 0, N - 1)
    FOR(j, 0, N - 1) FOR(k, 0, N - 1) ans[i][j] += u[i][k] * v[k][j];
    return ans;
  };
  vector<vector<ll>> I = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  while (b) {
    if (b & 1) {
      I = mult(I, A);
    }
    b >>= 1;
    A = mult(A, A);
  }
}
int32_t main() {
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
}
