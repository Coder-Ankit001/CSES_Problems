#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;
            if(c == '*') grid[i][j] = 1;
        }
    }

    if(grid[n-1][n-1] == 1 || grid[0][0] == 1){
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n-1][n-1] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == n-1 && j == n-1) continue;
            if(grid[i][j] == 1) continue;
            int right = 0, bottom = 0;
            if(j<n-1 && grid[i][j+1] == 0) right = dp[i][j+1];
            if(i<n-1 && grid[i+1][j] == 0) bottom = dp[i+1][j];
            dp[i][j] = (right + bottom) % MOD;
        }
    }

    int res = dp[0][0];
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