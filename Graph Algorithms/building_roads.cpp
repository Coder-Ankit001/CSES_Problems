#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;

    for(auto nei: adj[node]){
        if(vis[nei] == 1) continue;
        dfs(nei, adj, vis);
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

    vector<int> vis(n+1);
    vector<int> srcs;
    for(int i=1; i<=n; i++){
        if(vis[i] == 1) continue;
        srcs.push_back(i);
        dfs(i, adj, vis);
    }

    if(srcs.size() == 1){
        cout << 0 << endl;
        return;
    }

    cout << srcs.size() - 1 << endl;
    for(int i=1; i<srcs.size(); i++){
        cout << srcs[i-1] << " " << srcs[i] << endl;
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