#include"bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<ll>;

#define nl "\n"
#define pb push_back
#define all(x) begin(x),end(x)
#define TRA(x,a) for(auto &x : a)
#define FOR(i,a,b) for(int i = a;i<=b;i++)
//===================================================//


int n ;
map<int, int> m;

int32_t main()
{
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) { m[b[i]] = i; }
	for (int i = 0; i < n; i++) { a[i] = m[a[i]]; }

}