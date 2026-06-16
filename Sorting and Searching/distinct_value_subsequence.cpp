#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int MOD = (int)(1e9 + 7);

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        mp[val]++;
    }

    ll res = 1;
    for(auto[v, f]: mp){
        res = (res * (f + 1)) % MOD;
    }

    cout << res-1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}