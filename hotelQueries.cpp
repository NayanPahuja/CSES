#include <bits/stdc++.h>
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
typedef long long ll;
const ll N=2e5+1,mod=1e9+7;

int n,q;
ll a[N],seg_tree[4*N];

void build(int v = 1, int l = 1, int r = n) {
    if(l == r) seg_tree[v] = a[l];
    else {
        int m = l + (r - l) / 2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        seg_tree[v] = max(seg_tree[v*2],seg_tree[v*2+1]);
    }
}

void upd(int v, int l, int r, int new_val) {
    if(l > r) return;
    if(l == r) {
        seg_tree[v] -= new_val;
        cout << l << ' ';
    } else {
        int m = l + (r - l) / 2;
        if(seg_tree[v*2] >= new_val) upd(v*2,l,m,new_val);
        else upd(v*2+1,m+1,r,new_val);
        seg_tree[v] = max(seg_tree[v*2],seg_tree[v*2+1]);
    }
}

void solve(){
    cin >> n >> q;
    ilp(i,1,n) cin >> a[i];
    build();
    while(q--) {
        int x;
        cin >> x;
        if(seg_tree[1] < x) cout << 0 << ' ';
        else upd(1,1,n,x);
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) solve();
    return 0;
}