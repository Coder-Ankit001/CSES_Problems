#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" = "<< x << "\n";
#else
    #define debug(x)
#endif


void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;

    vector<ll> arr(n);
    for(auto& it: arr) cin >> it;

    long long res = 1;
    for(auto it: arr){
        if(it > res) break;
        res += it;
    }
    cout << res;
}

int main(){
    fast_io();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t = 1;
    while(t-->0) solve();
    
    return 0;
}