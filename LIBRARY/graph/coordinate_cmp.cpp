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

int n;
map<int, int> m;

int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    m[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = m[a[i]];
  }
}
