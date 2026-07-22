#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& it: v) cin >> it;

    ll sum1 = (ll)n * (n + 1) / 2;
    ll ssum1 = (ll)n * (n+1) * (2*n+1) / 6;
    ll sum2 = 0, ssum2 = 0;
    for(int i=0; i<n; i++){
        sum2 += v[i];
        ssum2 += (ll)v[i] * v[i];
    }

    ll diff = sum2 - sum1;
    ll sum = (ssum2 - ssum1) / diff;

    int missing = (sum - diff) / 2;
    cout << missing << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}