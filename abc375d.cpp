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
    string s;
    cin >> s;
    if(s.size() <= 2) {
        cout << 0 << '\n';
        return;
    } 
    string s_lowercase = s;
    transform(s_lowercase.begin(), s_lowercase.end(), s_lowercase.begin(), ::tolower);
    ll len = s_lowercase.size();
    vector<vector<ll>> prefSum(26, vector<ll>(len, 0));
    for(ll i = 0; i < 26; i++) {
        for(ll j = 0; j < len; j++) {
            prefSum[i][j] = (j > 0 ? prefSum[i][j-1] : 0) + (s_lowercase[j] == 'a' + i);
        }
    }

    ll res = 0;
    for(ll j = 1; j < len-1; j++) {
        ll sub_res = 0;
        for(ll i = 0; i < 26; i++) {
            ll left = prefSum[i][j-1];
            ll right = prefSum[i][len-1] - prefSum[i][j];
            sub_res += left*right;
        }
        res += sub_res;
    }

    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) solve();
    return 0;
}