#include <bits/stdc++.h>
typedef long long ll;
#define ilp(i,m,n) for (ll i=m;i<=n;i++)
#define dlp(i,m,n) for (ll i=m;i>=n;i--)
#define trv(i,vt) for (auto i:vt)
#define pll pair<ll,ll>
#define vec vector<ll>
#define vecpr vector<pll>
#define F first
// #define S second
#define pb push_back
using namespace std;

const ll mod = 1e9+7;
const int maxN = 5005, K = 26;

struct TrieNode {
    TrieNode* next[K];
    bool leaf = false;
    TrieNode() {ilp(i,0,K-1) next[i] = nullptr;}
};

class Trie {
    public:
        TrieNode* root;
        Trie() {root = new TrieNode();}
        void insert(string word) {
            TrieNode* node = root;
            trv(c,word) {
                if (node->next[c-'a'] == nullptr) node->next[c-'a'] = new TrieNode();
                node = node->next[c-'a'];
            }
            node->leaf = true;
        }
};


void solve(){
    Trie trie;
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ilp(i,1,n) {
        string word;
        cin >> word;
        trie.insert(word);
    }
    ll dp[maxN];
    memset(dp,0,sizeof(dp));
    dp[s.size()] = 1;
    dlp(i,s.size()-1,0) {
        TrieNode* node = trie.root;
        ilp(j,i,s.size()-1) {
            if (node->next[s[j]-'a'] == nullptr) break;
            node = node->next[s[j]-'a'];
            if (node->leaf) dp[i] = (dp[i] + dp[j+1]) % mod;
        }
    }
    cout << dp[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}



