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

ll a[N], dp[N+1];

void solve(){
    int n,x;
    cin >> n >> x;
    ilp(i,1,n) cin >> a[i];
    dp[0] = 1;
    ilp(i,1,x) {
        dp[i] = 0;
        ilp(j,1,n) {
            if (i - a[j] >= 0) {
                dp[i] += dp[i - a[j]];
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--) solve();
    return 0;
}