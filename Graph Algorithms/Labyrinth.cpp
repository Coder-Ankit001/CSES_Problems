#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
vector<char> dir = {'U', 'D', 'L', 'R'};
void bfs(int srow, int scol, int erow, int ecol, vector<vector<char>>& grid, int n, int m){

    vector<vector<bool>> vis(n,  vector<bool>(m, false));
    vector<vector<int>> path_dir(n,  vector<int>(m, false));
    queue<pair<int, int>> q;
    q.push({srow, scol});
    vis[srow][scol] = 1;

    bool found = false;
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();

        if(r == erow && c == ecol){
            found = true;
            break;
        }
        for(int i=0; i<4; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow < 0 || nrow == n || ncol < 0 || ncol == m || grid[nrow][ncol] == '#') continue;
            if(!vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                path_dir[nrow][ncol] = i;
                q.push({nrow, ncol});
            }
        }
    }


    if(!found){
        cout << "NO" << endl;
    }
    else{

        string path = "";
        int row = erow, col = ecol;
        while(row != srow || col != scol){
            int i = path_dir[row][col];
            path.push_back(dir[i]);
            row -= dr[i];
            col -= dc[i];
        }
        reverse(path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }
}
void solve(){
    int n, m;
    cin >> n >> m;

    int srow = -1, scol = -1;
    int erow = -1, ecol = -1;
    
    vector<vector<char>> grid(n, vector<char>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){ srow = i; scol = j; }
            if(grid[i][j] == 'B') { erow = i; ecol = j;}
        }
    }

    if(srow == -1 || erow == -1){
        cout << -1 << endl;
        return;
    }

    bfs(srow, scol, erow, ecol, grid, n, m);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}