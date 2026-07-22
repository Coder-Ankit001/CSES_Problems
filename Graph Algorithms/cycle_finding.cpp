#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int INF = 1e17;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }

    vector<ll> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    for(int i=0; i<n-1; i++){
        for(auto& e: edges){
            int u = e[0], v = e[1], wt = e[2];
            if(dist[u] != INF && dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }
    
    int affected = -1;
    for(auto& e: edges){
        int u = e[0], v = e[1], wt = e[2];
        if(dist[u] != INF && dist[v] > dist[u] + wt){
            dist[v] = dist[u] + wt;
            affected = v;
            parent[v] = u;
        }
    }

    if(affected == -1){
        cout << "NO" << endl;
        return;
    }

    int cur = affected;
    for(int i=0; i<n; i++) cur = parent[cur];

    vector<int> path;
    for(int x=cur; ;x=parent[x]){
        path.push_back(x);
        if(x == cur && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    for(auto it: path) cout << it << " ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    return 0;
}