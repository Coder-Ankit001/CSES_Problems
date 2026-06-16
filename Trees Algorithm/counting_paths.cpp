#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> parents, levels, pathSum;
vector<vector<int>> dp;
int LOG;
void kthAncestor(int n){
    LOG = log2(n) + 1;

    dp.resize(n+1, vector<int>(LOG, -1));
    for(int i=1; i<=n; i++) dp[i][0] = parents[i];

    for(int j=1; j<LOG; j++){
        for(int i=1; i<=n; i++){
            if(dp[i][j-1] == -1) continue;
            int par = dp[i][j-1];
            dp[i][j] = dp[par][j-1];
        }
    }
}

int lca(int u, int v){
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

void dfs(int depth, int node, int par){
    levels[node] = depth;
    for(int nei: tree[node]){
        if(nei == par) continue;
        parents[nei] = node;
        dfs(depth+1, nei, node);
    }
}

int dfs2(int node, int par){
    int sum = pathSum[node];
    for(int nei: tree[node]){
        if(nei == par) continue;
        sum += dfs2(nei, node);
    }
    return pathSum[node] = sum;
}

void solve(){
    int n, m;
    cin >> n >> m;

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

    pathSum.resize(n+1);
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        pathSum[from]++;
        pathSum[to]++;
        int L = lca(from, to);
        pathSum[L]--;
        if(parents[L] != 0){
            pathSum[parents[L]]--;
        }
    }

    dfs2(1, 0);
    for(int i=1; i<=n; i++){
        cout << pathSum[i] << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}