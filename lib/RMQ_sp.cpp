#include"bits/stdc++.h"
using namespace std;
#define int long long
#define nl "\n"

constexpr int LOG_N = 25;
constexpr int N = 2e5 + 10;

int l_flr(unsigned long i) { return bit_width(i) - 1; }

int st[LOG_N + 1][N];
int lg[N] = {0, 1};
vector<int> a(N);

int n , q;
int32_t main() {

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
	copy(a.begin(), a.end(), st[0]);
	for (int i = 1; i < LOG_N; i++) {
		for (int j = 0; (j + (1 << i)) - 1 < n; j++) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
	while (q--) {
		int a, b; cin >> a >> b;
		a--, b--;
		int k = l_flr(b - a + 1);
		cout << min(st[k][a], st[k][b - (1 << k) + 1 ]) << nl;
	}
}