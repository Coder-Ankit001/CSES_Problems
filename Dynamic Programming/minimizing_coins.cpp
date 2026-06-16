#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> prev(x+1, (int)1e8);
    prev[0] = 0;
    for(int ind=n-1; ind>=0; ind--){
        vector<int> cur(x+1, (int)1e8);
        cur[0] = 0;
        for(int tar=0; tar<=x; tar++){
            int pick = (int)1e8;
            if(tar - arr[ind] >= 0) pick = 1 + cur[tar-arr[ind]];
            int notPick = prev[tar];
            cur[tar] = min(pick, notPick);
        }
        prev = cur;
    }

    int res = prev[x] >= (int)1e8? -1: prev[x];
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