#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = (int)(1e9 + 7);

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int val=1; val<=n; val++){
        int cnt = 0;
        for(int k=1; k<=6; k++){
            if(val - k >= 0) cnt = (cnt + dp[val-k]) % MOD;
        }
        dp[val] = cnt % MOD;
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}