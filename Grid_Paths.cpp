#include "bits/stdc++.h"
using namespace std;

#define nl "\n"
#define int long long
#define all(s) s.begin(), s.end()
#define fo(i, k, n) \
  for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
constexpr int MOD = 1e9 + 7;
constexpr int N = 2e5 + 10;

#ifndef ONLINE_JUDGE
#include "bits/bug.hpp"
#endif

int n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<string> inp(n);
  fo(i, 0, n - 1) { cin >> inp[i]; }

  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  if (inp[0][0] == '*') {
    cout << 0 << nl;
    return 0;
  }
  dp[1][1] = 1;
  fo(i, 2, n) {
    fo(j, 1, n) {
      if (i == 1 && j == 1) {
        continue;
      }
      if (inp[i - 1][j - 1] == '*')
        dp[i][j] = 0;
      else
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + MOD) % MOD;
    }
  }
  cout << dp[n][n] << nl;
}
