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
    ll m,n;
    cin >> m >> n;
    
    // Input the matrix as strings of 0 and 1
    vector<string> mx(m+1);
    ilp(i,1,m) {
        cin >> mx[i];
        mx[i] = " " + mx[i];  // Add a space at the beginning to make it 1-indexed
    }
    
    ll q;
    cin >> q;
    
    // Difference array to track query updates
    vector<vector<ll>> df(m+2, vector<ll>(n+2, 0));
    
    while(q--) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Applying the difference array update technique
        df[x1][y1]++;
        df[x2+1][y1]--;
        df[x1][y2+1]--;
        df[x2+1][y2+1]++;
    }

    // Calculate prefix sum
    ilp(i, 1, m) {
        ilp(j, 1, n) {
            df[i][j] += df[i-1][j] + df[i][j-1] - df[i-1][j-1];
        }
    }

    // Apply the changes to the original matrix and print
    ilp(i,1,m) {
        ilp(j,1,n) {
            char c = mx[i][j];
            if (df[i][j] % 2 == 1) {
                c = (c == '0') ? '1' : '0';
            }
            cout << c;
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}