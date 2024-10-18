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

int helper(int index, vector<int>&a, int n, int m, int t, vector<vector<int>> &dp) {
    if(index >= n+1) return 0;
    if(dp[index][t] != -1) return dp[index][t];
    int notTake = helper(index+1, a, n, m, t, dp);
    int take = 0;
    if(t <= m) {
        take = a[index] * t + helper(index+1, a, n, m, t+1, dp);
    }
    return dp[index][t] = max(take, notTake);
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    int lneg = 0;
    ilp(i, 1, n) {
        cin >> a[i];
        if(a[i] < 0) lneg = min(lneg, a[i]);
    }
    ilp(i, 1, n) a[i] += -1 * lneg; // make all positive
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int res = helper(1, a, n, m, 1, dp);
    int calc = (m*(m+1)/2)* lneg;
    int finalRes = res + calc;
    cout << finalRes << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t =1;
    while (t--) solve();
    return 0;
}