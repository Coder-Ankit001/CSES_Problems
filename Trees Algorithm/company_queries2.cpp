#include <bits/stdc++.h>
using namespace std;

vector<int> parents;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<int> levels;
int LOG;


void kthAncestor(int n){
    LOG = log2(n) + 1;
    
    dp.resize(n+1, vector<int>(LOG, -1));
    for(int i=2; i<=n; i++) dp[i][0] = parents[i];
    
    for(int j=1; j<LOG; j++){
        for(int i=2; i<=n; i++){
            if(dp[i][j-1] == -1) continue;
            int par = dp[i][j-1];
            dp[i][j] = dp[par][j-1];
        }
    }
}

int binaryLift(int u, int v){
    // Make them at same level
    if(levels[u] < levels[v]) swap(u, v);
    int diff = levels[u] - levels[v];
    for(int i=0; i<LOG; i++){
        if((diff >> i) & 1) u = dp[u][i];
        if(u == -1) return -1;
    }

    if(u == v) return u;

    // Move them simulataneously
    for(int i=LOG-1; i>=0; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
            if(u == -1) return -1;
        }
    }
    return dp[u][0];
}

void dfs(int node, vector<int>& path){
    path.push_back(node);
    levels[node] = path.size() - 1;
    for(auto nei: tree[node]){
        dfs(nei, path);
    }
    path.pop_back();
}

void solve(){
    int n, q;
    cin >> n >> q;

    parents.resize(n+1);
    tree.resize(n+1);
    for(int i=2; i<=n; i++){
        int par;
        cin >> par;
        parents[i] = par;
        tree[par].push_back(i);
    }

    kthAncestor(n);

    levels.resize(n+1);
    vector<int> path;
    dfs(1, path);

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        cout << binaryLift(u, v) << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}