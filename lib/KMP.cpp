#include "bits/stdc++.h"
using namespace std;


int main() {
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
