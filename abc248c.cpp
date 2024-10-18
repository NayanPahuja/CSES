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
const ll N=1e6+5,mod=998244353;

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;

}


void solve(){
    int N,M,K;
    cin >> N >> M >> K;
    ll dp[N+1][K+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            for(int k = 1; k <= M; k++) {
                if (j + k <= K) dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]) % mod;
            }
        }
    }

    ll res = 0;
    for(int i = 1; i <=K; i++) {
        res += dp[N][i] % mod;
    }

    cout << res % mod << endl;
}


int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--) solve();
    return 0;
}