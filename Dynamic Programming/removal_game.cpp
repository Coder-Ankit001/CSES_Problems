#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1e9;

ll findScore(int i, int j, vector<int>& nums, int n, vector<vector<ll>>& dp){
    if(i > j) return 0LL;
    if(dp[i][j] != -1) return dp[i][j];

    ll left = (ll)nums[i] - findScore(i+1, j, nums, n, dp);
    ll right = (ll)nums[j] - findScore(i, j-1, nums, n, dp);
    return dp[i][j] = (ll)max(left, right);
}
void solve(){
    int n;
    cin >> n;

    ll sum = 0;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll diff = findScore(0, n-1, nums, n, dp);
    ll first = (sum - diff) / 2LL + diff;
    cout << first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}