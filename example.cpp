//TEMPLATE : NAYAN
//ALWAYS CHECK EXAMPLE AND CORNER TC

#include <bits/stdc++.h>
typedef long long ll;
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
const ll N=1e6+5, mod=1e9+7;

int longestConsecutivePeriod(){
    ll n, k; //n length k billing cycle
    cin >> n >> k;
    vector<ll> dailyexp(n);
    
    for(int i = 0; i < n; i++) cin >> dailyexp[i];
    ll cntPositives = 0;
    for(auto i : dailyexp) {
        if (i >= 0) cntPositives++;
    }
    if(cntPositives == 0) {
        return 0; //no case possible
    }
    unordered_map<ll, ll> remainder_map; //map  indexes
    remainder_map[0] = -1; //if subarray starts frrom beginning

    ll prefix_sum = 0, result = 0;

    ilp(i, 0, n-1) {
        prefix_sum += dailyexp[i];
        ll remainder = prefix_sum % k;
        
        //handle the edge case if remainder is negative
        if (remainder < 0) remainder += k;

        // use map to search if we have seen remainder
        if (remainder_map.find(remainder) != remainder_map.end()) {
            ll subarray_length = i - remainder_map[remainder];
            result = max(result, subarray_length); //this could be a potential answer , check if it is greater than our current answer
        } else {
            remainder_map[remainder] = i;
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) cout << longestConsecutivePeriod() << '\n';
    
    return 0;
}
