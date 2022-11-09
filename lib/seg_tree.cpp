#include"bits/stdc++.h"
using namespace std;
constexpr int N =  2e5 + 10;

struct segtree {
	int sz;
	vector<int> tr;
	segtree(int n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		tr = vector<int> (2 * sz, 0LL);
	}

};

int n , q;
int a[N];
int main() {
	segtree* sgt = new segtree();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (q--) {
		int a, b , c;
		cin >> a >> b >> c;
		if (a == 1) {

		} else {

		}
	}

}