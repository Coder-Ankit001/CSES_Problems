#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto nei: adj[node]){
        if(vis[nei]) continue;
        dfs(nei, adj, vis);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<vector<int>> revAdj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    int color = 1;
    dfs(1, adj, vis);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << 1 << " " << i;
            return;
        }
    }

    vector<int> vis2(n+1, 0);
    dfs(1, revAdj, vis2);
    for(int i=1; i<=n; i++){
        if(!vis2[i]){
            cout << "NO\n";
            cout << i << " " << 1;
            return;
        }
    }
    cout << "YES" << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}