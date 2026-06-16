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
    if(levels[u] < levels[v]) swap(u, v);
    int diff = levels[u] - levels[v];

    for(int i=LOG-1; i>=0; i--){
        if((diff >> i) & 1) u = dp[u][i];
    }

    if(u == v) return u;

    for(int i=LOG-1; i>=0; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int dist(int u, int v){
    int lca = binaryLift(u, v);
    return levels[v] + levels[u] - 2 * levels[lca];
}

void dfs(int depth, int node, int par){
    levels[node] = depth;
    for(int nei: tree[node]){
        if(nei == par) continue;
        parents[nei] = node;
        dfs(depth+1, nei, node);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    tree.resize(n+1);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    parents.resize(n+1);
    levels.resize(n+1);
    dfs(0, 1, 0);

    kthAncestor(n);

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << " ";
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