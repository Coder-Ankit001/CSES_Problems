#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, -1, 0, 1};
vector<char> dir = {'U', 'L', 'D', 'R'};

void bfs(vector<vector<char>>& grid, int n, int m){
    vector<vector<int>> monster_dist(n, vector<int>(m, INF));
    
    queue<pair<int, int>> q;
    int startR = -1, startC = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'M' ) {
                q.push({i, j});
                monster_dist[i][j] = 0;
            }
            else if(grid[i][j] == 'A') {
                startR = i;
                startC = j;
            }
        }
    }
    
    if(startR == 0 || startC == 0 || startR == n-1 || startC == m-1){
        cout << "YES\n0\n";
        return;
    }
    
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            
            if(nrow < 0 || nrow == n || ncol < 0 || ncol == m || grid[nrow][ncol] == '#') continue;
            if(1 + monster_dist[r][c]  < monster_dist[nrow][ncol]){
                monster_dist[nrow][ncol] = 1 + monster_dist[r][c];
                q.push({nrow, ncol});
            }
        }
    }
    
    while(!q.empty()) q.pop();
    
    vector<vector<int>> person_dist(n, vector<int>(m, INF));
    vector<vector<int>> path_dir(n, vector<int>(m, 0));

    bool found = false;
    int endR = -1, endC = -1;
    person_dist[startR][startC] = 0;
    q.push({startR, startC});
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        if((person_dist[r][c] < monster_dist[r][c]) && (r == 0 || c == 0 || r == n-1 || c == m-1)){
            endR = r; endC = c;
            found = true;
            break;
        }
        for(int i=0; i<4; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow < 0 || nrow == n || ncol < 0 || ncol == m || grid[nrow][ncol] == '#') continue;
            if(1 + person_dist[r][c] < person_dist[nrow][ncol]){
                person_dist[nrow][ncol] = 1 + person_dist[r][c];
                path_dir[nrow][ncol] = i;
                q.push({nrow, ncol});
            }
        }
    }

    if(!found){
        cout << "NO" << endl;
    }
    else{
        int r = endR, c = endC;
        vector<char> path;
        while(r != startR || c != startC){
            int d = path_dir[r][c];
            path.push_back(dir[d]);
            r -= dr[d];
            c -= dc[d];
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        for(auto it=path.rbegin(); it<path.rend(); it++){
            cout << *it;
        }
        cout << endl;
    }
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> grid[i][j];
    }

    bfs(grid, n, m);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();


    return 0;
}