#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

void solve(int i) {
	string A , B; cin >> A >> B;
	vi store(100);
	for(auto x : A){
		store[x-'a']++;
	}
	ll ans = 0;
	for( auto x : B ){
		 if( store[x-'a'] >0){
			store[x-'a']--;
			ans++;
		 }
	}
	cout << ( !ans ? -1 : ans ) << "\n";
}

int main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	ll test = 1;  
	//cin >> test;

	for (int t = 1; t <= test; t++) {
		solve(test);
	}
}
