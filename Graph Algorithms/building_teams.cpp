#include <bits/stdc++.h>
using namespace std;

bool bipartite(int node, int color, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = color; // 2 -> Group B | 1 -> Group A
    for(auto nei: adj[node]){
        if(vis[nei] == color) return false;
        if(vis[nei] == 1-color) continue;
        if(!bipartite(nei, 1-color, adj, vis)) return false;
    }
    return true;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;
    vector<int> vis(n+1, -1);
    for(int i=1; i<=n; i++){
        if(vis[i] != -1) continue;
        if(!bipartite(i, 1, adj, vis)){
            isBipartite = false;
            break;
        }
    }

    if(!isBipartite){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int i=1; i<=n; i++){
            cout << vis[i] + 1 << " ";
        }
        cout << endl;
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