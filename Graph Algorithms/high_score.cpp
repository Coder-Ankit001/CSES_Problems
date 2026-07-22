#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;
void dfs(int node, vector<bool>& reachable, vector<vector<int>>& adj){
    reachable[node] = true;
    for(auto it: adj[node]){
        if(!reachable[it]) dfs(it, reachable, adj);
    }
}
ll bellman(int src, int n, vector<vector<int>>& edges){

    vector<ll> dist(n+1, INF);
    dist[src] = 0;
    for(int i=0; i<n-1; i++){
        for(auto& e: edges){
            int u = e[0], v = e[1];
            ll wt = e[2];
            if(dist[u] != INF && dist[v] > wt + dist[u]){
                dist[v] = wt + dist[u];
            }
        }
    }

    vector<vector<int>> revAdj(n+1);
    for(auto& e: edges){
        revAdj[e[1]].push_back(e[0]);
    } 

    vector<bool> reachable(n+1, false);

    dfs(n, reachable, revAdj);

    for(auto& e: edges){
        int u = e[0], v = e[1];
        ll wt = e[2];
        if(dist[u] != INF && dist[v] > wt + dist[u] && reachable[u]) return -1;
    }
    return -1LL*dist[n];
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, -1*wt};
    }

    cout << bellman(1, n, edges) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}