#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, -1, 0, 1};
void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
    int n = grid.size();
    int m = grid[0].size();

    vis[r][c] = 1;

    for(int i=0; i<4; i++){
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow < 0 || nrow == n || ncol < 0 || ncol == m || grid[nrow][ncol] == '#') continue;
        if(!vis[nrow][ncol]) dfs(nrow, ncol, grid, vis);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n,  vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> grid[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] || grid[i][j] == '#') continue;
            dfs(i, j, grid, vis);
            cnt++;
        }
    }

    cout << cnt << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}