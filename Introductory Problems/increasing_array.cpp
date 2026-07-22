#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& it: v) cin >> it;

    ll count = 0;
    for(int i=1; i<n; i++){
        if(v[i] >= v[i-1]) continue;
        count += v[i-1] - v[i];
        v[i] = v[i-1];
    }
    cout << count << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}