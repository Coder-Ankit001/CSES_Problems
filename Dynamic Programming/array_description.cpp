#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;


vector<vector<int>> dp;

int findCount(int ind, int prev, int n, int m, vector<int>& arr){
    if(ind == n) return 1;
    if(prev > m || prev <= 0) return 0;
    if(dp[ind][prev] != -1) return dp[ind][prev];
    
    if(arr[ind] != 0){
        int res = 0;
        if(abs(prev-arr[ind]) <= 1) res = findCount(ind+1, arr[ind], n, m, arr);
        return dp[ind][prev] = res;
    }
    else{
        int left=0, center=0, right=0;
        if(prev > 1) left = findCount(ind+1, prev-1, n, m, arr);
        center = findCount(ind+1, prev, n, m, arr);
        if(prev < m) right = findCount(ind+1, prev+1, n, m, arr);
        return dp[ind][prev] = (((left + right) % MOD) + center) % MOD;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];


    dp.resize(n, vector<int>(m+1, -1));
    int res = 0;
    if(arr[0] == 0){
        for(int i=1; i<=m; i++) res = (res + findCount(1, i, n, m, arr)) % MOD;
    }
    else res = findCount(1, arr[0], n, m, arr);
    
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