#include"bits/stdc++.h"
using namespace std;

struct DSU {
	vector<int> par, sz;
	DSU(int n) {
		par = vector<int> (n + 10); sz = vector<int> (n + 10);
		for (int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
	}
	int get(int i) {
		if (par[i] == i) return i;
		return par[i] = get(par[i]);
	}
	bool unn(int a, int b) {
		a = get(a), b = get(b);
		if ( a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a; sz[a] += sz[b];
		return 1;

	}
	int sze(int a) { return sz[get(a)];}
};

int main() {
	DSU *d = new DSU(100);
}