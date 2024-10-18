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
const ll N=2005,mod=1e9+7;
 
bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}

ll a[N];
ll dp[N+1][N+1];

ll helper(ll index, ll a[], ll n, ll m, ll t, ll dp[][N+1]) { 
	if(index >=n+1) {
		return 0;
	}
	if(dp[index][t] != -1) return dp[index][t];
	// not take
	ll notTake = helper(index+1, a, n, m, t, dp);
	ll take = 0;
	if(t <= m) {
		take = a[index] * t + helper(index+1, a, n, m, t+1, dp);
	}
	return dp[index][t] = max(take, notTake);
}
 
void solve(){
	ll n, m;
	cin >> n >> m;
	ll lneg = 0;
	ilp(i, 1, n) {
		cin >> a[i];
		if(a[i] < 0) lneg = min(lneg, a[i]);
	}
    // cout << "lneg: " << lneg << '\n';
	ilp(i, 1, n) a[i] += -1 * lneg; // make all positive
    // for(ll i = 1; i <=n; i++) cout << a[i] << ' ';
    // cout << '\n';
	memset(dp, 0, sizeof(dp)); 
	

	for(ll i = n; i >=1;i--) {
		for(ll t = m; t >=1;t--) {
			ll notTake = dp[i+1][t];
			ll take = 0;
			if(t <= m) take = a[i]*t + dp[i+1][t+1];
			dp[i][t] = max(take, notTake);
		}
	}
	ll res = dp[1][1];
	ll calc = (m*(m+1)/2)* lneg;
	ll finalRes = res + calc;
	cout << finalRes << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    ll t = 1;
    while (t--) solve();
    return 0;
}