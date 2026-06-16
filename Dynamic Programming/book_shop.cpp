#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

int INF = (int)1e8;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> book(n), pages(n);
    for(int i=0; i<n; i++) cin >> book[i];
    for(int i=0; i<n; i++) cin >> pages[i];

    vector<int> prev(x+1);

    for(int ind=n-1; ind>=0; ind--){
        vector<int> cur(x+1);
        for(int tar=0; tar<=x; tar++){
            int pick = -INF;
            if(tar - book[ind] >= 0) pick = pages[ind] + prev[tar-book[ind]];
            int notPick = prev[tar];
            cur[tar] = max(pick, notPick);
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