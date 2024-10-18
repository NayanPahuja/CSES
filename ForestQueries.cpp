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

void solve(){
    ll n,q;
    cin >> n >> q;
    
    // Input the matrix as strings of 0 and 1
    vector<vector<ll>> mx(n+1,vector<ll>(n+1,0));
    ilp(i,1,n) {
        ilp(j,1,n) {

        char c;
        cin >> c;
        if(c == '.') mx[i][j] = 0;
        else mx[i][j] = 1;
        }
    }
    ilp(i, 1, n) {
        ilp(j, 1, n) {
            mx[i][j] += mx[i-1][j]+ mx[i][j-1] - mx[i-1][j-1];
        }
    }
    while(q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << mx[x2][y2] - mx[x1-1][y2] - mx[x2][y1-1] + mx[x1-1][y1-1] << '\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}