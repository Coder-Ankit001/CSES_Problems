#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> vec(n);
    for(auto& it: vec) cin >> it;

    sort(all(vec));
    int cnt = unique(all(vec)) - vec.begin();

    cout << cnt << "\n";
}


int main(){
    fast_io();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    while (t--) solve();
    return 0;
}