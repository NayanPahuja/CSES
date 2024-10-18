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


long long a[N], seg_tree[4*N];

void build(long long a[], int v, int tl, int tr) {
    if (tl == tr) {
        seg_tree[v] = a[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        seg_tree[v] = seg_tree[v*2] + seg_tree[v*2+1];
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return seg_tree[v];
    int tm = tl + (tr - tl) / 2;
    return sum(v*2,tl,tm,l,min(r,tm)) + sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v, int tl, int tr, int pos, long long new_val) {
    if(tl == tr) {
        seg_tree[v] = new_val;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            update(v*2,tl,tm,pos,new_val);
        }
        else {
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        seg_tree[v] = seg_tree[v*2] + seg_tree[v*2+1];
    }
}
void solve(){
    int n,q;
    cin >> n >> q;
    ilp(i,1,n) cin >> a[i];
    build(a,1,1,n);
    ilp(i,1,q) {
        int type;
        cin >> type;
        if(type == 1){
            int k;
            ll u;
            cin >> k >>  u;
            update(1,1,n,k,u);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout << sum(1,1,n,l,r) << '\n';
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}