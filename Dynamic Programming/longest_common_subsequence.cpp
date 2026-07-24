#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);
    for(auto& it: nums1) cin >> it;

    vector<int> nums2(m);
    for(auto& it: nums2) cin >> it;


    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // Base Case dp[0...n][m] = 0 | dp[n][0...m] = 0
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(nums1[i] == nums2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    vector<int> res;
    // BackTrack
    int i = 0, j = 0;
    while(i < n && j < m){
        if(nums1[i] == nums2[j]){
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j] >= dp[i][j+1]) i++;
        else j++;
    }

    cout << res.size() << endl;
    for(auto it: res) cout << it << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}