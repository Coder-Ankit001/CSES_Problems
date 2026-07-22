#include <bits/stdc++.h>
using namespace std;

void bfs(int V, vector<vector<int>>& adj){
    int snode = 1, enode = V;

    vector<int> parent(V+1, -1);
    vector<int> vis(V+1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    bool found = false;
    while(!q.empty()){
        auto node = q.front(); q.pop();
        if(node == enode){
            found = true;
            break;
        }
        for(auto nei: adj[node]){
            if(vis[nei] == 1) continue;
            vis[nei] = 1;
            parent[nei] = node;
            q.push(nei);
        }
    }

    if(!found){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path;
        int it = enode;
        path.push_back(it);
        while(parent[it] != -1){
            path.push_back(parent[it]);
            it = parent[it];
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for(auto it: path) cout << it << " ";
        cout << endl;
    }
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

    bfs(n, adj);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}