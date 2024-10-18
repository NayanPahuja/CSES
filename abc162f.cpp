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




void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k_max = n / 2;
    vector<ll> dp(k_max + 1, LLONG_MIN);
    vector<ll> prev_dp(k_max + 1, LLONG_MIN);
    vector<ll> prev_prev_dp(k_max + 1, LLONG_MIN);
    dp[0] = 0;
    prev_dp[0] = 0;
    prev_prev_dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int k = 0; k <= k_max; k++) {
            dp[k] = prev_dp[k];
            if (k > 0 && i > 1 && prev_prev_dp[k - 1] != LLONG_MIN) {
                dp[k] = max(dp[k], prev_prev_dp[k - 1] + a[i - 1]);
            }
            if(i == 1 && k == 1) dp[k] = a[0];
        }
        prev_prev_dp = prev_dp;
        prev_dp = dp;   
    }
    cout << dp[k_max] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) solve();
    return 0;
}