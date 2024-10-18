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

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}


void solve(){
    int n;
    cin >> n;
    string s[n];
    ilp(i,0,n-1) cin >> s[i];
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    if(s[0][0] == '*') dp[0][0] = 0;
    ilp(i,0,n-1){
        ilp(j,0,n-1) {
            if(s[i][j] == '*') continue;
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1] << endl;

}
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) solve();
    return 0;
}