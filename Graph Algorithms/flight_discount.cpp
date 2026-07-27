#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll INF = 1e18;

ll findCost(int n, vector<vector<pair<int, ll>>>& adj) {
    // dist[0..n][0] -> no coupon used
    // dist[0..n][1] -> coupon used
    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));

    dist[1][0] = 0LL;
    dist[1][1] = 0LL;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
    pq.push({0LL, 1, 0});

    while(!pq.empty()){
        auto [cost, node, used] = pq.top(); pq.pop();
        if(used == 0 && dist[node][0] < cost) continue;
        if(used == 1 && dist[node][1] < cost) continue;
        for(auto [nei, wt]: adj[node]){
            if(used == 0){
                if(dist[nei][0] > wt + cost){
                    dist[nei][0] = wt + cost;
                    pq.push({dist[nei][0], nei, used});
                }
                if(dist[nei][1] > (wt/2) + cost){
                    dist[nei][1] = (wt/2) + cost;
                    pq.push({dist[nei][1], nei, 1});
                }
            }
            if(used == 1){
                if(dist[nei][1] > wt + cost){
                    dist[nei][1] = wt + cost;
                    pq.push({dist[nei][1], nei, used});
                }
            }
        }
    }
    return min(dist[n][0], dist[n][1]);
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    cout << findCost(n, adj) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}