#include"bits/stdc++.h"
using namespace std;

const int LOG = 25;
const int MAX_N = 1e5 + 10;

int n, q;
int ar[MAX_N];
int spt[LOG][MAX_N];

int qry(int l , int r) {
	int lr = (r - l + 1);
	int p = 0;
	while (1 << (p + 1) <= lr)p++;
	return min(spt[p][l] , spt[p][r - (1 << p) + 1 ]);
}
int main() {
	cin >> n ;
	for (int i = 0; i < n; i++) { cin >> ar[i]; spt[0][i] = ar[i];}

	// preprocessing of O(n*log(MAX_N))
	for (int p = 1 ; p < LOG; p++ ) {
		for (int j = 0; j + (1 << p) - 1 < n; j++)	{
			spt[p][j] = min(spt[p - 1][j], spt[p - 1][j + (1 << (p - 1))]);
		}
	}

	//  process the queries in [l,r] inclusive
	cin >> q;
	while (q--) {
		int l , r; cin >> l >> r;
		cout << qry(l, r) << endl;
	}

}
