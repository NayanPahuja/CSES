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

void solve()
{
    multiset<ll> mul;
    int n;cin>>n;
    while(n -- ){
        char op[2];cin>>op;
        ll k,x;

        if(*op == '1'){
            cin>>x;
            mul.insert(x);
        }else if(*op == '2'){
            cin>>x>>k;

            auto it = mul.upper_bound(x);
            while(k && it!=mul.begin()){
                k -- ;
                it -- ;

            }
            if(k){
                cout<<-1<<endl;
            }else{
                cout<<*it<<endl;
            }
        }else if(*op  == '3'){
            cin>>x>>k;
            auto it = mul.lower_bound(x);
            while(k && it!=mul.end()){
                k -- ;
                it++;
            }

            if(k){
                cout<<-1<<endl;
            }else{
                it--;
                cout<<*it<<endl;
            }
        }
    }   
}


int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
