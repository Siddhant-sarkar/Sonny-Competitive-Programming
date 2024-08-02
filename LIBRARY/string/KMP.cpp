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


int main()
{
	string s;
	cin >> s;
	int n = s.size();

	int lps[n + 1]; lps[0] =  -1;
	int i = 0 , j = -1;
	while ( i < n) {
		while (j != -1 && s[j] != s[i] ) j = lps[j];
		j++, i++; lps[i] = j;
	}
	for (int k = 0; k <= n; k++)
		cout << lps[k] << " ";


}
