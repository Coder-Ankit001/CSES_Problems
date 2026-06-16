#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> dp(x+1);
    dp[0] = 1;
    for(int tar=1; tar<=x; tar++){
        for(int ind=0; ind<n; ind++){
            if(tar - arr[ind] < 0) break;
            if((ll)dp[tar] + dp[tar-arr[ind]] >= MOD) dp[tar] = (dp[tar] + dp[tar-arr[ind]]) % MOD;
            else dp[tar] += dp[tar-arr[ind]];
        }
    }

    int res = dp[x];
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}