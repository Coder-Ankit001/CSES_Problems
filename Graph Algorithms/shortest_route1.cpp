#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;
vector<ll> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj){

    vector<ll> dist(n+1, INF);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [cost, node] = pq.top(); pq.pop();
        if(cost > dist[node]) continue;
        for(auto [adjNode, edgW]: adj[node]){
            if(dist[adjNode] > cost + edgW){
                dist[adjNode] = cost + edgW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<ll> res = dijkstra(1, n, adj);
    for(auto i=1; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}