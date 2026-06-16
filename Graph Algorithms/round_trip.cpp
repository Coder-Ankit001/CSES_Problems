#include <bits/stdc++.h>
using namespace std;

int cycle_end = -1;
int cycle_start = -1;
bool dfs(int node, int par, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent){
    parent[node] = par;
    vis[node] = 1;
    
    for(auto nei: adj[node]){
        if(vis[nei] == 1){
            if(nei == par) continue;
            cycle_end = node;
            cycle_start = nei;
            return true;
        }
        if(dfs(nei, node, adj, vis, parent)) return true;
    }
    return false;
}
void solve(){
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    vector<int> parent(n+1, -1);
    vector<int> vis(n+1, 0);
    
    for(int i=1; i<=n; i++){
        if(vis[i] != 0) continue;
        if(dfs(i, -1, adj, vis, parent)){
            cycle = true;
            break;
        }
    }

    if(!cycle) {
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path;
        int node = cycle_end;
        
        while(node != cycle_start){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(cycle_start);
        path.push_back(cycle_end);
        
        cout << path.size() << "\n";
        for(auto it: path) cout << it << " ";
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}