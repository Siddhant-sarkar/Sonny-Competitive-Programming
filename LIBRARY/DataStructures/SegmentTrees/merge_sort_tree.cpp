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

const int N = 1e5 + 5;
int n, q, a[N];
multiset<int> seg[4 * N + 5];

void build(int x, int lt, int rt)
{
    if (lt == rt) {
        seg[x].insert(a[lt]);
        return;
    }
    int mid = (lt + rt) / 2;
    build(x * 2, lt, mid);
    build(x * 2 + 1, mid + 1, rt);
    for (int i = lt; i <= rt; i++) seg[x].insert(a[i]);
}
void update(int x, int lt, int rt, int p, int v)
{
    if (lt == rt) {
        seg[x].erase(a[p]);
        seg[x].insert(v);
        return;
    }
    int mid = (lt + rt) / 2;
    if (p <= mid) update(x * 2, lt, mid, p, v);
    else update(x * 2 + 1, mid + 1, rt, p, v);
    seg[x].erase(a[p]);
    seg[x].insert(v);
    return;
}
int query(int node, int l, int r, int lx, int rx, int x)
{
    if (l > rx || r < lx) return INT_MAX;
    if (l >= lx && r <= rx) {
        auto it = seg[node].lower_bound(x);
        if (it == seg[node].end()) return INT_MAX;
        return *it;
    } int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, lx, rx, x), query(node * 2 + 1, mid + 1, r, lx, rx, x));
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
