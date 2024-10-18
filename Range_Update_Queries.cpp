#include <bits/stdc++.h>
typedef long long ll;
#define ilp(i,m,n) for (ll i=m;i<=n;i++)
using namespace std;

const ll N = 2e5 + 5;  // Increased size by 1 to avoid out of bounds
ll a[N], seg_tree[4 * N], lazy[4 * N];

// Building the segment tree
void build(ll a[], int v, int l, int r) {
    if (l == r) {
        seg_tree[v] = a[l];
    } else {
        int m = l + (r - l) / 2;
        build(a, v * 2, l, m);
        build(a, v * 2 + 1, m + 1, r);
        seg_tree[v] = seg_tree[v * 2] + seg_tree[v * 2 + 1];
    }
}

// Propagate lazy updates
void lazyprop(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        seg_tree[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

// Update the range [l, r] by adding new_val
void update(int v, int tl, int tr, int l, int r, long long new_val) {
    lazyprop(v, tl, tr);  // Ensure pending updates are propagated
    if (l > r) return;    // No overlap case

    if (l == tl && r == tr) {
        lazy[v] += new_val;
        lazyprop(v, tl, tr);
    } else {
        int m = (tl + tr) / 2;
        update(v * 2, tl, m, l, min(r, m), new_val);
        update(v * 2 + 1, m + 1, tr, max(l, m + 1), r, new_val);
        seg_tree[v] = seg_tree[v * 2] + seg_tree[v * 2 + 1];  // Update the parent node
    }
}

// Query the value at a single position (pos)
ll range_query(int v, int tl, int tr, int pos) {
    lazyprop(v, tl, tr);  // Ensure lazy updates are applied
    if (tl == tr) {
        return seg_tree[v];  // Leaf node
    } else {
        int m = (tl + tr) / 2;
        if (pos <= m)
            return range_query(v * 2, tl, m, pos);
        else
            return range_query(v * 2 + 1, m + 1, tr, pos);
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    ilp(i, 1, n) cin >> a[i];  // Input array using 1-based indexing
    build(a, 1, 1, n);         // Build the segment tree

    ilp(i, 1, q) {
        int type;
        cin >> type;
        if (type == 1) {
            ll a, b, u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);  // Range update
        } else if (type == 2) {
            ll k;
            cin >> k;
            cout << range_query(1, 1, n, k) << '\n';  // Point query
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
