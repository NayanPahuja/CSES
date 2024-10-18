#include <bits/stdc++.h>
#define ll long long
#define ilp(i,m,n) for (ll i=m;i<=n;i++)
#define dlp(i,m,n) for (ll i=m;i>=n;i--)
#define trv(i,vt) for (auto &i:vt)
#define pll pair<ll,ll>
#define vec vector<ll>
#define vecpr vector<pll>
#define F first
#define S second
#define pb push_back
using namespace std;
const ll N=5005,mod=1e9+7;

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}

ll a[N];
ll dp[N+1][N+1];

ll helper(int s, int e, int turn, ll a[], ll dp[][N+1]) {
    if (s > e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    if(turn == 0) {
        dp[s][e] = max(a[s] + helper(s+1,e,1,a,dp), a[e] + helper(s,e-1,1,a,dp));
    } else {
        dp[s][e] = min(helper(s+1,e,0,a,dp), helper(s,e-1,0,a,dp));
    }
    return dp[s][e];
}


void solve(){
    ll n;
    cin >> n;
    ilp(i,1,n) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << helper(1,n,0,a,dp) << '\n';
}

//iterative
//still don't know how to do it

void solve1() {
    ll n;
    cin >> n;
    vector<int> v(n);
    ll sum = 0;
    trv(i,v) {
        cin >> i;
        sum += i;
    }
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int l = n-1; l >=0; l--) {
        for(int r = l; r < n; r++) {
            if(l == r) dp[l][r] = v[l];
            else dp[l][r] = max(v[l] - dp[l+1][r], v[r] - dp[l][r-1]);
        }
    }

    cout << (sum + dp[0][n-1])/2 << '\n';

}
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) solve1();
    return 0;
}