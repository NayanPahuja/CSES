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
const ll N=2e5, mod=1e9+7;

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}

void solve(){
    int n;
    cin >> n;
    vec A(n);
    ilp(i, 0, n-1) cin >> A[i];
    
    vec cnt(N+1, 0);
    
    ilp(i, 0, n-1) cnt[A[i]]++;
    
    ilp(i, 0, N-1) cnt[i+1] += cnt[i];
    
    ll ans = 0;
    ilp(j, 0, n-1){
        ans += cnt[A[j]-1] * (n - cnt[A[j]]);
    }
    
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--) solve();

    return 0;
}
