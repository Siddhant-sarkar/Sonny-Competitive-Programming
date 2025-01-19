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
int a, b, d, k;
vi num;
int dp[12][12][2];

int call(int pos, int cnt, int f) {
  // terminating conditions
  if (cnt > k) return 0;
  if (pos == num.size()) return cnt == k;
  if (dp[pos][cnt][f] != -1) return dp[pos][cnt][f];

  // defining limits
  int LMT, res = 0;
  if (f == 0)
    LMT = num[pos];
  else
    LMT = 9;
  // looping for all digits
  for (int dgt = 0; dgt <= LMT; dgt++) {
    int ncnt = cnt;
    int nf = f;
    if (f == 0 && dgt < LMT) nf = 1;  // checking if number getting smaller
    if (dgt == d) ncnt++;             // checking if count of D increasing
    if (ncnt <= k) res += call(pos + 1, ncnt, nf);  // only call if count <=k
  }
  return dp[cnt][pos][f] = res;
}
int _dp(int a) {
  num.clear();
  while (a) {
    num.push_back(a % 10);
    a /= 10;
  }
  reverse(begin(num), end(num));
  memset(dp, -1, sizeof(dp));
  return call(0, 0, 0);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> a >> b >> d >> k;
  cout << _dp(b) - _dp(a - 1) << nl;
}