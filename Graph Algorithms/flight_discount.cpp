#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;

struct Tuple{
    int node, used;
    ll cost;
    Tuple(int n, int u, ll c): node(n), used(u), cost(c) {}
};
struct Comp{
    bool operator() (Tuple& a, Tuple& b){
        return a.cost > b.cost;
    }
};

long long findCost(int n, vector<vector<pair<int, int>>>& adj){
    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));
    dist[1][0] = 0LL;

    priority_queue<Tuple, vector<Tuple>, Comp> pq;
    pq.push(Tuple(1, 0, 0LL));
    while(!pq.empty()){
        Tuple t = pq.top(); pq.pop();
        int node = t.node, used = t.used;
        ll cost = t.cost;

        if(dist[node][used] < cost) continue;

        for(auto [nei, wt]: adj[node]){
            if(dist[nei][used] > cost + wt){
                dist[nei][used] = cost + wt;
                pq.push(Tuple(nei, used, dist[nei][used]));
            }

            if(used == 0){
                if(dist[nei][1] > cost + (wt / 2)){
                    dist[nei][1] = cost + (wt / 2);
                    pq.push(Tuple(nei, 1, dist[nei][1]));
                }
            }
        }
    }
    return dist[n][1];
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

    cout << findCost(n, adj) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}