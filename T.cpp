#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = std::vector<ll>;
using vvi = std::vector<vi>;
using pii = std::pair<ll, ll>;

#define nl "\n"
#define F first
#define S second
#define pb push_back
#define sz(a) (ll)a.size();
#define all(a) begin(a),end(a)
#define TRA(it, a) for(auto &it : a)
#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define ROF(i,a,b) for(ll i=a; i>=b; i--)
#define __CHINI__ cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);

constexpr ll INF = 2e18;
constexpr ll MOD = 1e9 + 7;
constexpr long double EPS = 1e-16;

template <typename T1, typename T2>
ostream& operator<<(ostream& ostream, const pair<T1, T2>& p) { return (ostream << p.first << " " << p.second); }
template <typename T> istream& operator>>(istream& istream, vector<T>& v) { for (auto& it : v) cin >> it; return istream; }
template <typename T1, typename T2> istream& operator>>(istream& istream, pair<T1, T2>& p) { return (istream >> p.first >> p.second); }
template < class T, class = decltype(begin(declval<T>())), class = enable_if_t < !is_same<T, string>::value >>
ostream & operator<<(ostream &os, const T &c) { for (auto &it : c ) os << it << " "; return os; }

template <typename T> void print(T&& t) { cout << t << "\n"; }
template <typename T, typename... Args> void print(T&& t, Args &&...args) { cout << t << " "; print(forward<Args>(args)...); }

void solve( ll tc ) {

}

int main() {
	cout.tie(0); cin.tie(0); ios::sync_with_stdio(false);
	ll t = 1; cin >> t;
	FOR(i, 1, t) solve(t);
}