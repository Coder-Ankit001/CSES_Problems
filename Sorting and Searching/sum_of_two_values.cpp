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

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for(auto& it: v) cin >> it;

    ll maxSum = INT_MIN;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += v[i];
    }
}

int main(){
    fast_io();

    solve();
    return 0;
}