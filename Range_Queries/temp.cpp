#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define umap unordered_map
#define vec vector

void precompute(vec<string>& k, umap<char,pll>& kPos) {
    k = {
        "qwertyuiop",
        "asdfghjkl.",
        ".zxcvbnm.."
    };
    for (int i = 0; i < k.size(); i++) {
        for (int j = 0; j < k[i].size(); j++) {
            kPos[k[i][j]] = {i, j};
        }
    }
}

char ctlower(char &a) {
    if (a >= 'A' && a <= 'Z') {
        return (char)(a + 32);
    }
    return a;
}

ll getDist(pll &a, pll &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(string &s) {
    vec<string> keyboard;
    umap<char,pll> keyPos;
    precompute(keyboard, keyPos);
    pll currPos = keyPos['q'];
    ll res = 0;
    for (char i : s) {
        i = (char)ctlower(i);
        pll nextPos = keyPos[i];
        res += getDist(currPos, nextPos);
        currPos = nextPos;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    cout << solve(str) << '\n';
    return 0;
}
