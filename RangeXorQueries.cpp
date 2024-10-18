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
const ll N=2e5,mod=1e9+7;

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}

ll a[N], seg_tree[4*N];

ll doXor(ll a, ll b){
    return a ^ b;
}

void build(ll a[], int v, int l, int r) {
    if(l == r) {
        seg_tree[v] = a[l];
    } else {
        int m = l + (r - l)/2;
        build(a,v*2,l,m);
        build(a,v*2+1,m+1,r);
        seg_tree[v] = doXor(seg_tree[v*2],seg_tree[v*2+1]);
    }
}

ll xorQ(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return seg_tree[v];
    int m = (tl + (tr - tl)/2);
    return doXor(xorQ(v*2,tl,m,l,min(r,m)),xorQ(v*2+1,m+1,tr,max(l,m+1),r));
}

void solve(){
    int n,q;
    cin >> n >> q;
    ilp(i,1,n) cin >> a[i];
    build(a,1,1,n);
    ilp(i,1,q) {
        int l,r;
        cin >> l >> r;
        cout << xorQ(1,1,n,l,r) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) solve();
    return 0;
}