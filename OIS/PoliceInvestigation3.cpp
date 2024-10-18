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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);

        for(int i = 3; i <=n; i++) {
            int incl = dp[i-2] + nums[i-1];
            int excl = dp[i-1];
            dp[i] = max(incl,excl);
        }
        return dp[n];
    }




int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int sum = 0;
        trv(i,nums) sum += i;
        cout << sum - rob(nums) << endl;
    }

    return 0;
}