#include <bits/stdc++.h>
using namespace std;

// defines
using ll = long long;
using vi = std::vector<ll>;
using vvi = std::vector<vi>;
using pii = std::pair<ll, ll>;

// macros
#define nl "\n"
#define F first
#define S second
#define sz(a) (ll) a.size();
#define all(a) begin(a), end(a)
#define TRA(it, a) for (auto &it : a)
#define FOR(i, a, b) for (int i = a; i <= (int)b; i++)
#define ROF(i, a, b) for (int i = a; i >= (int)b; i--)
#define _lalalalala_ \
  cout.tie(0);       \
  cin.tie(0);        \
  ios::sync_with_stdio(false);

// Debug - template import
#ifndef ONLINE_JUDGE
#include "bits/bug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// I/O overloads
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
  return (ostream << p.first << " " << p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
  for (auto &it : v)
    cin >> it;
  return istream;
}
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
  return (istream >> p.first >> p.second);
}
template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c)
{
  for (auto &it : c)
    os << it << " ";
  return os;
}
template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
  cout << t << " ";
  print(forward<Args>(args)...);
}

// consts
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9 + 7;
constexpr long double EPS = 1e-16;

// 1 2 3 4 5 6 7 8;
void solve(ll tc)
{
  ll n;
  cin >> n;
  // Calculate the total sum of numbers from 1 to n
  ll total_sum = (1ll * n * (1ll * n + 1)) / 2;

  // Check if the total sum is odd, if so, it's not
  // possible to divide into two equal halves
  if (total_sum % 2 != 0)
  {
    cout << "NO\n";
  }
  else
  {
    cout << "YES\n";

    // Initialize vectors for set1, set2, and a vector
    // to keep track of visited elements
    vector<int> set1, set2;
    vector<int> vis(n + 1, 0);

    // Initialize set1_sum and max_element
    ll set1_sum = 0;
    ll max_element = n;

    // Loop to fill set1
    while (set1_sum < total_sum / 2)
    {
      // Calculate remaining sum needed to make
      // set1_sum equal to total_sum / 2
      ll remaining_sum = total_sum / 2 - set1_sum;

      // If remaining_sum is greater than the maximum
      // element, add the maximum element to set1
      if (remaining_sum > max_element)
      {
        set1.push_back(max_element);
        vis[max_element] = 1;
        set1_sum += max_element;
        max_element--;
      }
      else
      {
        // If remaining_sum is less than or equal to
        // the maximum element, add remaining_sum to
        // set1
        set1.push_back(remaining_sum);
        vis[remaining_sum] = 1;
        set1_sum = total_sum / 2;
      }
    }

    // Loop to fill set2 with non-picked elements
    for (int i = 1; i <= n; i++)
    {
      if (vis[i] == 0)
      {
        set2.push_back(i);
      }
    }

    // Print the size and elements of set1
    cout << set1.size() << "\n";
    for (auto x : set1)
    {
      cout << x << " ";
    }
    cout << "\n";

    // Print the size and elements of set2
    cout << set2.size() << "\n";
    for (auto x : set2)
    {
      cout << x << " ";
    }
  }
}

int main()
{
  _lalalalala_ ll t = 1;
  // cin >> 1;
  FOR(i, 1, t) { solve(t); }
}
