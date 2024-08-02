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


constexpr ll MOD =  1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll N = 1e6 + 9;

void harmonic()
{
	vector<ll> a(N);
	for (int i = 1; i < N ; i++) {
		for (int j = i ; j < N; j += i) {
			a[j]++;
		}
	}
	cout << " the numbers are \n";
	FOR(i , 1 , 100) {
		cout << a[i] << " ";
	}
	cout << "\n";

}



int32_t main()
{
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	harmonic();
}

