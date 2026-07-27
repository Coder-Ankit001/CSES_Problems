#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = 1e9 + 7;
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll modexp(ll a, ll n){
    if(n == 0) return 1;

    ll half = modexp(a, n/2);
    if(n % 2) return mul(half, mul(half, a));
    return mul(half, half);
}
ll inv(int a){
    return modexp(a, MOD-2);
}
ll findWays(int ind, int sum, int target, int n, vector<vector<int>>& dp){
    if(sum == target) return 1;
    if(ind > n) return 0;
    if(dp[ind][sum] != -1) return dp[ind][sum];

    ll pick = 0;
    if(sum + ind <= target) pick = findWays(ind+1, sum+ind, target, n, dp);
    ll notPick = findWays(ind+1, sum, target, n, dp);
    return dp[ind][sum] = (int)add(pick, notPick);
}
void solve(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> nums(n);
    for(int i=1; i<=n; i++){
        sum += i;
    }

    if(sum % 2){
        cout << 0 << "\n";
        return;
    }

    int half = sum / 2;
    vector<vector<int>> dp(n+1, vector<int>(half+1, -1));
    int ways = findWays(1, 0, half, n, dp);
    cout << mul(ways, inv(2)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}