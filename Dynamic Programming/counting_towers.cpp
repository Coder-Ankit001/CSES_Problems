#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = (int)(1e9 + 7);

ll dp[1000001][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1; dp[1][1] = 1;
    for(int i=1; i<1000000; i++){
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i+1][0] += 2 * dp[i][0];
        dp[i+1][1] += dp[i][0];
        dp[i+1][0] += dp[i][1];
        dp[i+1][1] += 4 * dp[i][1];
    }

    int t;
    cin >> t;
    while(t-->0) {
        int n;
        cin >> n;
        ll ans = (dp[n][0] + dp[n][1]) % MOD;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}