#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int findPath(int node, int last, vector<vector<int>>& adj, vector<int>& child, vector<int>& dp){
    if(node == last) return 0;
    if(dp[node] != -1) return dp[node];
    int maxDepth = -INF;
    for(auto nei: adj[node]){
        int depth = findPath(nei, last, adj, child, dp);
        if(depth != -INF && maxDepth < 1 + depth){
            maxDepth = 1 + depth;
            child[node] = nei;
        }
    }
    return dp[node] = maxDepth;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dp(n+1, -1);
    vector<int> child(n+1, -1);
    int res = findPath(1, n, adj, child, dp);
    if(res == -INF){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    vector<int> path;
    int cur = 1;
    while(cur != -1){
        path.push_back(cur);
        cur = child[cur];
    }
    cout << path.size() << "\n";
    for(auto& it: path) cout << it << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}