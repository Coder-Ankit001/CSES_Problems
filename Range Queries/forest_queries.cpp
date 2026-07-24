#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin >> c;
            int left = pref[i][j-1];
            int up = pref[i-1][j];
            int diag = pref[i-1][j-1];

            pref[i][j] = (c == '*') + left + up - diag;
        }
    }

    for(int i=0; i<q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int upper = pref[r1-1][c2];
        int left = pref[r2][c1-1] - pref[r1-1][c1-1];
        cout << pref[r2][c2] - upper - left << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}