#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int bfs(int src, vector<vector<int>>& tree){
    int n = tree.size();

    vector<int> dist(n+1, -1);
    dist[src] = 0;
    res[src] = max(res[src], dist[src]);

    queue<int> q;
    q.push(src);

    int node = src;
    while(q.size()){
        node = q.front(); q.pop();
        for(auto nei: tree[node]){
            if(dist[nei] != -1) continue;
            dist[nei] = dist[node] + 1;
            res[nei] = max(res[nei], dist[nei]);
            q.push(nei);
        }
    }
    return node;
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    res.resize(n+1, -1);
    int endA = bfs(1, tree);
    int endB = bfs(endA, tree);
    bfs(endB, tree);

    for(int i=1; i<=n; i++) cout << res[i] << " ";
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