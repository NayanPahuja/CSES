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

// link for concept https://cp-algorithms.com/string/lyndon_factorization.html


    bool solve(int l , int r, string &s,  vector<vector<int>> &dp) {
        if(l>=r) return 1;

        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        if(s[l] == s[r]) dp[l][r] = solve(l+1,r-1,s,dp);
        else dp[l][r] = false;
        return dp[l][r];
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int startingIndex = 0;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(i,j,s,dp)) { //means its a palindrome
                    if((j-i+1) > maxLen) { //new substring is greater than previously found
                        startingIndex = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startingIndex,maxLen);
    }

int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--) {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}