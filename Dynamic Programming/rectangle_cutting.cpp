#include <bits/stdc++.h>
using namespace std;

int INF = 1e8;
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == j) continue;

            int minMoves = INF;
            for(int k=1; k<i; k++){
                minMoves = min(minMoves, (1 + dp[k][j] + dp[i-k][j]));
            }
            for(int k=1; k<j; k++){
                minMoves = min(minMoves, (1 + dp[i][k] + dp[i][j-k]));
            }
            dp[i][j] = minMoves;
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}