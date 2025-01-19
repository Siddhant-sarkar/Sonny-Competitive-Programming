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
vector<int> ar;
vector<int> bt;

// when updating : we move up in the series so there is the +.
void update(int i, int v) {
  for (; i <= N; i += (i & -i)) bt[i] += v;
}

// when sum : we sum till it gets down so there is the -.
int qry(int l, int r) {
  auto sm = [&](int i) -> int {
    int rt = 0;
    for (; i > 0; i -= (i & -i)) rt += bt[i];
    return rt;
  };
  return sm(r) - sm(l - 1);
}
int32_t main() {
  cin.tie(0);
  cout.tie(0)->sync_with_stdio(0);
  cin >> N;
  ar.resize(N);
  bt.resize(N + 1);

  for (int i = 0; i < N; i++) {
    cin >> ar[i];
  }
  // constructing
  for (int i = 1; i <= N; i++) {
    update(i, ar[i - 1]);
  }
  cout << qry(1, 7) << endl;
}
