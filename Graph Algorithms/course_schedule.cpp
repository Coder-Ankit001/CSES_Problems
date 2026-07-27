#include <bits/stdc++.h>
using namespace std;

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
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(auto nei: adj[i]) indegree[nei]++;
    }
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> sorted;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nei: adj[node]){
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei);
        }
        sorted.push_back(node);
    }

    if(sorted.size() < n) {
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto it: sorted) cout << it << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("io/input.txt", "r", stdin);
    // freopen("io/output.txt", "w", stdout);

    solve();
    return 0;
}