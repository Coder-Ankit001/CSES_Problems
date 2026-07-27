#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD = 1e9 + 7;
ll INF = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<ll> dist(n+1, INF);
    vector<ll> ways(n+1, 0);
    vector<int> shortestFlight(n+1, 1e9), longestFlight(n+1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0LL, 1});
    dist[1] = 0LL;
    ways[1] = 1;
    shortestFlight[1] = 0;
    longestFlight[1] = 0;

    while(!pq.empty()){
        auto [cost, node] = pq.top(); pq.pop();
        if(dist[node] < cost) continue;
        for(auto [nei, wt]: adj[node]){
            if(dist[nei] > wt + cost){
                dist[nei] = wt + cost;
                pq.push({dist[nei], nei});
                ways[nei] = ways[node];
                shortestFlight[nei] = shortestFlight[node] + 1;
                longestFlight[nei] =  longestFlight[node] + 1;
            }
            else if(dist[nei] == wt + cost){
                ways[nei] = (ways[nei] + ways[node]) % MOD;
                shortestFlight[nei] = min(shortestFlight[nei], shortestFlight[node] + 1);
                longestFlight[nei] = max(longestFlight[nei], longestFlight[node] + 1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << shortestFlight[n] << " " << longestFlight[n] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}