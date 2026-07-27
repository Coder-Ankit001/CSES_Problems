#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<ll> vis(n+1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0LL, 1});
    ll totalCost = 0;
    while(!pq.empty()){
        auto [cost, node] = pq.top(); pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        totalCost += cost;
        for(auto [nei, wt]: adj[node]){
            if(vis[nei]) continue;
            pq.push({wt, nei});
        }
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
    }
    cout << totalCost << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}