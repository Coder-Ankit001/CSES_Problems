#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;

bool dfs(int node, int n,vector<vector<pair<int, ll>>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto [nei, wt]: adj[node]){
        if(vis[nei]) continue;
        if(nei == n) return true; 
        if(dfs(nei, n, adj, vis)) return true;
    }
    return false;
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> edges(m);
    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, -1LL*wt};
        adj[u].push_back({v, wt});
    }


    vector<ll> dist(n+1, INF);
    dist[1] = 0LL;

    for(int i=0; i<n-1; i++){
        for(auto& e: edges){
            int u = e[0], v = e[1];
            ll wt = e[2];
            if(dist[u] != INF && dist[v] > wt + dist[u]){
                dist[v] = wt + dist[u];
            }
        }
    }

    vector<bool> infected(n+1, false);
    for(auto& e: edges){
        int u = e[0], v = e[1];
        ll wt = e[2];
        if(dist[u] != INF && dist[v] > wt + dist[u]){
            dist[v] = wt + dist[u];
            infected[v] = true;
        }
    }

    if(infected[n]){
        cout << -1 << "\n";
        return;
    }

    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(infected[i] && !vis[i]){
            if(dfs(i, n, adj, vis)){
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << -1LL * dist[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}