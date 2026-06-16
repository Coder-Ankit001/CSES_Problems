#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> prev(x+1);
    prev[0] = 1;
    for(int ind=n-1; ind>=0; ind--){
        vector<int> cur(x+1);
        cur[0] = 1;
        for(int tar=1; tar<=x; tar++){
            int pick = 0;
            if(tar - arr[ind] >= 0) pick = cur[tar-arr[ind]];
            int notPick = prev[tar];
            cur[tar] = (pick + notPick) % MOD;
        }
        prev = cur;
    }

    int res = prev[x];
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