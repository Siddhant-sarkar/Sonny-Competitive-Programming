#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = std::vector<ll>;
using vvi = std::vector<vi>;
using pii = std::pair<ll, ll>;

#define nl "\n"
#define F first
#define S second
#define sz(a) (ll)a.size();
#define all(a) begin(a),end(a)
#define TRA(it, a) for(auto &it : a)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define ROF(i,a,b) for(int i=a; i>=b; i--)
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

//======================================Veni, vidi, vici===来た、見た、勝った===============================>
void solve( ll tc ) {
    ll n; cin >> n;
    vi cost(n), type(n);

    FOR(i, 0, n - 1) {
        cin >> cost[i];
        string k ; cin >> k;
        ll ms = 0;
        FOR(j, 0, size(k) - 1) {
            ms |= (1 << (k[j] - 'A'));
        }
        type[i] = ms;
    }
    // print(type);
    vvi dp(n + 10, vi(8, INF));
    dp[0][0] = 0;
    FOR(i, 0, n - 1) {
        for (int j = 0; j < 8; j++) {
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]) ;
            dp[i + 1][j | type[i]] = min(dp[i + 1][j | type[i]], dp[i][j] + cost[i] );
        }
    }
    if ( dp[n][7] == INF) {print(-1);}
    else print(dp[n][7]);

}

int main() {
    __CHINI__
    ll t = 1;
    // cin >> t;
    FOR(i, 1, t) solve(t);
}