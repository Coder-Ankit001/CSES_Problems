#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, 
    vector<int>& parent, int& cycleStart, int& cycleEnd){
    vis[node] = 1;
    for(auto nei: adj[node]){
        if(vis[nei] == 1){
            cycleStart = nei;
            cycleEnd = node;
            return true;
        }
        else if(vis[nei] == -1){
            parent[nei] = node;
            if(dfs(nei, adj, vis, parent, cycleStart, cycleEnd)) return true;
            parent[nei] = -1;
        }
    }
    vis[node] = 0;
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
    }

    vector<int> parent(n+1, -1);
    vector<int> vis(n+1, -1);
    int cycleStart = -1, cycleEnd = -1;
    for(int i=1; i<=n; i++){
        if(vis[i] != -1) continue;
        parent[i] = -1;
        if(dfs(i, adj, vis, parent, cycleStart, cycleEnd)) break;
    }

    if(cycleEnd == -1 || cycleStart == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;
    int cur = cycleEnd;
    path.push_back(cycleStart);
    while(cur != cycleStart){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(cycleStart);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto it: path) cout << it << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}