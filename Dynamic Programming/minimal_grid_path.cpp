#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1e9;

void solve(){
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int dr[2] = {1, 0};
    int dc[2] = {0, 1};

    queue<pair<int, int>> q;
    q.push({0, 0});

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;

    string ans;
    ans += grid[0][0];

    while (ans.size() < 2 * n - 1){
        int sz = q.size();
        vector<pair<int, int>> nxt;
        char best = 'Z' + 1;
        while (sz-->0){
            auto [r, c] = q.front(); q.pop();

            for (int k = 0; k < 2; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= n || nc >= n || vis[nr][nc]) continue;
                if (grid[nr][nc] < best){
                    best = grid[nr][nc];
                    nxt.clear();
                }

                if (grid[nr][nc] == best){
                    vis[nr][nc] = 1;
                    nxt.push_back({nr, nc});
                }
            }
        }
        ans += best;
        for (auto &p : nxt) q.push(p);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();

    return 0;
}