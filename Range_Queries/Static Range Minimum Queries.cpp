#include <bits/stdc++.h>
#define ll long long
#define ilp(i,m,n) for (ll i=m;i<=n;i++)
#define dlp(i,m,n) for (ll i=m;i>=n;i--)
#define trv(i,vt) for (auto i:vt)
#define pll pair<ll,ll>
#define vec vector<ll>
#define vecpr vector<pll>
#define F first
#define S second
#define pb push_back
using namespace std;
const ll N=1e6+5,mod=1e9+7;
const int maxN =  2e5+5;
const int LOG = 17;

ll a[maxN], st[maxN][LOG]; // a >> array st >> sparse table
ll bin_log[maxN]; // precomputed log2(i) for i in [1, n]

ll query(){
    ll L, R;
    cin >> L >> R;
    ll length = R - L + 1;
    ll k = bin_log[length];
    return min(st[L][k], st[R - (1 << k) + 1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    
    // Precompute logarithms
    bin_log[1] = 0;
    for (int i = 2; i <= n; i++) {
        bin_log[i] = bin_log[i / 2] + 1;
    }
    
    // Read input and initialize sparse table
    ilp(i, 1, n) {
        cin >> a[i];
        st[i][0] = a[i];
    }

    // Preprocess sparse table
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i + (1 << k) - 1 <=n; i++) {
            st[i][k] = min(st[i][k-1], st[i + (1 << (k-1))][k-1]);
        }
    }

    // Answer the queries
    while (q--) {
        cout << query() << endl;
    }
    return 0;
}
