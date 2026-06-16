#include <bits/stdc++.h>
using namespace std;

int INF = (int)1e9;
int findDistance(int i, int j, string& s, string& t, vector<vector<int>>& dp){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;
    if(dp[i][j] != -1) return dp[i][j];

    int res = INF;
    if(s[i] == t[j]) res = min(res, findDistance(i-1, j-1, s, t, dp));
    else{
        int chng = 1 + findDistance(i-1, j-1, s, t, dp);
        int add = 1 + findDistance(i, j-1, s, t, dp);
        int del = 1 + findDistance(i-1, j, s, t, dp);
        res = min(res, min(add, min(del, chng)));
    }
    return dp[i][j] = res;
}

void solve(){
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << findDistance(n-1, m-1, s, t, dp) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();

    return 0;
}