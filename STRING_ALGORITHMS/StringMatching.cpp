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


vector<int> z_function(const string &s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


void solve(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    string temp = t + "$" + s;
    vector<int> z = z_function(temp);
    ll cnt = 0;
    ilp(i,t.size()+1,temp.size()-1) if (z[i] == t.size()) cnt++;
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}