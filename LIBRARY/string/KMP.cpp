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

int main() {
  string s;
  cin >> s;
  int n = s.size();

  int lps[n + 1];
  lps[0] = -1;
  int i = 0, j = -1;
  while (i < n) {
    while (j != -1 && s[j] != s[i]) j = lps[j];
    j++, i++;
    lps[i] = j;
  }
  for (int k = 0; k <= n; k++) cout << lps[k] << " ";
}
