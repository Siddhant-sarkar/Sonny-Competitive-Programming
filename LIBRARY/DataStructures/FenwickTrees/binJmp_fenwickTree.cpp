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

int N;
vector<int> ar, bit;

int qry(int l, int r) {
  auto sum = [&](int i) -> int {
    int rt = 0;
    for (; i > 0; i -= (i & -i)) {
      rt += bit[i];
    }
    return rt;
  };
  return sum(r) - sum(l - 1);
}
void update(int i, int v) {
  for (; i <= N; i += (i & -i)) {
    bit[i] += v;
  }
}
int lw_bound(int x) {
  int cp = 0, csum = 0;
  for (int i = log2(x); i >= 0; i--) {
    if (bit[cp + (1 << i)] + csum < x) {
      cp = cp + (1 << i);
      csum += bit[cp];
    }
  }
  return ++cp;
}

int main() {
  cin >> N;
  ar.resize(N + 1);
  bit.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> ar[i];
    update(i, ar[i]);
  }

  cout << qry(1, N) << endl;
}
