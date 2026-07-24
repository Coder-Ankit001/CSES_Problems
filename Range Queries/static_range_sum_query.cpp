#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve(){
    int n, q;
    cin >> n >> q;

    vector<ll> pref(n+1);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pref[i+1] = pref[i] + num;
    }

    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("./io/input.txt", "r", stdin);
    // freopen("./io/output.txt", "w", stdout);

    solve();

    return 0;
}