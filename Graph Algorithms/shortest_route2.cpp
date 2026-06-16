#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;
void warshalls(int n, vector<vector<ll>>& dist){
    for(int i=1; i<=n; i++) dist[i][i] = 0;

    for(int via=1; via<=n; via++){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                if(dist[u][via] == INF || dist[via][v] == INF) continue;
                if(dist[u][v] > dist[u][via] + dist[via][v]){
                    dist[u][v] = dist[u][via] + dist[via][v];
                }
            }
        }
    }
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        dist[u][v] = min<ll>(dist[u][v], wt);
        dist[v][u] = min<ll>(dist[v][u], wt);
    }

    warshalls(n, dist);

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        if(dist[u][v] == INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
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