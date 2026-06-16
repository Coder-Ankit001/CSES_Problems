#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> dp(n+1);
    dp[0] = 0;
    for(int val=1; val<=n; val++){
        int num = val;
        int res = (int)1e8;
        while(num){
            int dig = num % 10;
            num /= 10;
            if(dig == 0) continue;
            int steps = (int)1e8;
            if(val-dig >=0) steps = 1 + dp[val-dig];
            res = min(res, steps);
        }
        dp[val] = res;
    }

    int res = dp[n];
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}