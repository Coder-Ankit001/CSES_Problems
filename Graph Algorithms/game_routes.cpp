#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n; i++){
        for(auto nei: adj[i]) indegree[nei]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ways(n+1, 0);
    ways[1] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nei: adj[node]){
            if(ways[node] != 0) {
                ways[nei] = (ways[nei] + ways[node]) % MOD;
            }
            if(--indegree[nei] == 0){
                q.push(nei);
            }
        }
    }
    cout << ways[n] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}